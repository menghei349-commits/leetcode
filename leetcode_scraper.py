"""
抓取自己 LeetCode 帳號資料：
1. 已解題目清單 -> solved_problems.csv
2. 每題最新一次 Accepted 的程式碼 -> solutions/<frontend_id>-<slug>.<ext>

使用方式：
    1. 複製 config.example.json 為 config.json，填入你的 LEETCODE_SESSION / csrftoken
       (登入 leetcode.com 後，開 DevTools -> Application -> Cookies 複製)
    2. python leetcode_scraper.py
"""

import csv
import json
import re
import sys
import time
from pathlib import Path

import requests

BASE_URL = "https://leetcode.com"
GRAPHQL_URL = f"{BASE_URL}/graphql"
SUBMISSIONS_URL = f"{BASE_URL}/api/submissions/"

CONFIG_PATH = Path(__file__).parent / "config.json"
SOLUTIONS_DIR = Path(__file__).parent / "solutions"
CSV_PATH = Path(__file__).parent / "solved_problems.csv"

REQUEST_DELAY_SEC = 0.6

LANG_EXTENSION = {
    "python": "py",
    "python3": "py",
    "c": "c",
    "cpp": "cpp",
    "csharp": "cs",
    "java": "java",
    "javascript": "js",
    "typescript": "ts",
    "php": "php",
    "swift": "swift",
    "kotlin": "kt",
    "dart": "dart",
    "golang": "go",
    "ruby": "rb",
    "scala": "scala",
    "rust": "rs",
    "racket": "rkt",
    "erlang": "erl",
    "elixir": "ex",
    "mysql": "sql",
    "mssql": "sql",
    "oraclesql": "sql",
    "postgresql": "sql",
}

PROBLEMSET_QUERY = """
query problemsetQuestionList($categorySlug: String, $limit: Int, $skip: Int, $filters: QuestionListFilterInput) {
  problemsetQuestionList: questionList(
    categorySlug: $categorySlug
    limit: $limit
    skip: $skip
    filters: $filters
  ) {
    total: totalNum
    questions: data {
      frontendQuestionId: questionFrontendId
      title
      titleSlug
      difficulty
      status
      topicTags {
        name
      }
    }
  }
}
"""


def load_config() -> dict:
    if not CONFIG_PATH.exists():
        sys.exit(
            f"找不到 {CONFIG_PATH}。請先複製 config.example.json 為 config.json 並填入你的 cookie。"
        )
    with open(CONFIG_PATH, encoding="utf-8") as f:
        config = json.load(f)
    if "在瀏覽器" in config.get("leetcode_session", ""):
        sys.exit("config.json 裡的 leetcode_session / csrf_token 還沒填入實際值。")
    return config


def build_session(config: dict) -> requests.Session:
    session = requests.Session()
    session.cookies.set("LEETCODE_SESSION", config["leetcode_session"], domain="leetcode.com")
    session.cookies.set("csrftoken", config["csrf_token"], domain="leetcode.com")
    session.headers.update(
        {
            "Content-Type": "application/json",
            "Referer": BASE_URL,
            "x-csrftoken": config["csrf_token"],
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) leetcode-scraper/1.0",
        }
    )
    return session


def check_login(session: requests.Session) -> str:
    query = """
    query globalData {
      userStatus {
        isSignedIn
        username
      }
    }
    """
    resp = session.post(GRAPHQL_URL, json={"query": query})
    resp.raise_for_status()
    data = resp.json()["data"]["userStatus"]
    if not data["isSignedIn"]:
        sys.exit("登入失敗，請確認 config.json 裡的 cookie 是否正確、是否已過期。")
    print(f"登入成功，帳號：{data['username']}")
    return data["username"]


def fetch_solved_problems(session: requests.Session) -> list[dict]:
    print("正在抓取題目清單與解題狀態...")
    all_questions = []
    skip = 0
    limit = 100
    while True:
        variables = {
            "categorySlug": "",
            "skip": skip,
            "limit": limit,
            "filters": {},
        }
        resp = session.post(
            GRAPHQL_URL,
            json={"query": PROBLEMSET_QUERY, "variables": variables},
        )
        resp.raise_for_status()
        payload = resp.json()["data"]["problemsetQuestionList"]
        questions = payload["questions"]
        all_questions.extend(questions)
        skip += limit
        if skip >= payload["total"] or not questions:
            break
        time.sleep(REQUEST_DELAY_SEC)

    solved = [q for q in all_questions if q["status"] == "ac"]
    print(f"共 {len(all_questions)} 題，已解出 {len(solved)} 題。")
    return solved


def write_solved_csv(solved: list[dict]) -> None:
    with open(CSV_PATH, "w", newline="", encoding="utf-8-sig") as f:
        writer = csv.writer(f)
        writer.writerow(["frontend_id", "title", "title_slug", "difficulty", "tags"])
        for q in sorted(solved, key=lambda x: int(x["frontendQuestionId"])):
            tags = ";".join(t["name"] for t in q["topicTags"])
            writer.writerow(
                [q["frontendQuestionId"], q["title"], q["titleSlug"], q["difficulty"], tags]
            )
    print(f"已寫入 {CSV_PATH}")


def fetch_accepted_submissions(session: requests.Session) -> dict:
    """回傳 {title_slug: submission_dict}，每題只保留最新一次 Accepted。"""
    print("正在抓取提交紀錄（可能需要一點時間）...")
    latest_by_slug: dict[str, dict] = {}
    offset = 0
    page_size = 20
    last_key = ""

    while True:
        params = {"offset": offset, "limit": page_size}
        if last_key:
            params["lastkey"] = last_key
        resp = session.get(SUBMISSIONS_URL, params=params)
        if resp.status_code == 429:
            print("被限速，等待 5 秒後重試...")
            time.sleep(5)
            continue
        resp.raise_for_status()
        data = resp.json()
        submissions = data.get("submissions_dump", [])
        if not submissions:
            break

        for sub in submissions:
            if sub.get("status_display") != "Accepted":
                continue
            slug = sub["title_slug"]
            # submissions_dump 依時間新到舊排列，第一次遇到即為最新
            if slug not in latest_by_slug:
                latest_by_slug[slug] = sub

        if not data.get("has_next"):
            break
        offset += page_size
        last_key = data.get("last_key", "")
        time.sleep(REQUEST_DELAY_SEC)

    print(f"共取得 {len(latest_by_slug)} 題的最新 Accepted 提交。")
    return latest_by_slug


def sanitize(name: str) -> str:
    return re.sub(r'[\\/:*?"<>|]', "_", name).strip()


def save_solutions(submissions: dict, solved_meta: list[dict]) -> None:
    """依每題的第一個 topic tag 分類存放，檔名帶上難度方便辨識。"""
    SOLUTIONS_DIR.mkdir(exist_ok=True)
    slug_to_meta = {q["titleSlug"]: q for q in solved_meta}

    saved = 0
    for slug, sub in submissions.items():
        code = sub.get("code")
        if not code:
            continue
        lang = sub.get("lang", "txt")
        ext = LANG_EXTENSION.get(lang, "txt")

        meta = slug_to_meta.get(slug)
        frontend_id = meta["frontendQuestionId"] if meta else "0"
        difficulty = meta["difficulty"] if meta else "Unknown"
        title = meta["title"] if meta else slug
        tags = meta["topicTags"] if meta else []
        primary_tag = sanitize(tags[0]["name"]) if tags else "Uncategorized"

        target_dir = SOLUTIONS_DIR / primary_tag
        target_dir.mkdir(exist_ok=True)

        safe_title = sanitize(title).replace(" ", "-")
        filename = f"{frontend_id}-{safe_title}-{difficulty}.{ext}"
        filepath = target_dir / filename
        filepath.write_text(code, encoding="utf-8")
        saved += 1

    print(f"已將 {saved} 份程式碼依分類存到 {SOLUTIONS_DIR}")


def main() -> None:
    config = load_config()
    session = build_session(config)
    check_login(session)

    solved = fetch_solved_problems(session)
    write_solved_csv(solved)

    submissions = fetch_accepted_submissions(session)
    save_solutions(submissions, solved)


if __name__ == "__main__":
    main()
