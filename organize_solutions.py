"""
依 solved_problems.csv 裡的標籤(tag)，把 solutions/ 內既有的程式碼分類到子資料夾。
每題用第一個 topic tag 當分類資料夾，檔名加入難度方便辨識。

使用方式：
    python organize_solutions.py
"""

import csv
import re
from pathlib import Path

SOLUTIONS_DIR = Path(__file__).parent / "solutions"
CSV_PATH = Path(__file__).parent / "solved_problems.csv"


def sanitize(name: str) -> str:
    return re.sub(r'[\\/:*?"<>|]', "_", name).strip()


def load_metadata() -> dict:
    metadata = {}
    with open(CSV_PATH, encoding="utf-8-sig") as f:
        for row in csv.DictReader(f):
            metadata[row["frontend_id"]] = {
                "title": row["title"],
                "slug": row["title_slug"],
                "difficulty": row["difficulty"],
                "tags": [t for t in row["tags"].split(";") if t],
            }
    return metadata


def main() -> None:
    metadata = load_metadata()
    slug_lookup = {m["slug"]: (fid, m) for fid, m in metadata.items()}

    moved = 0
    skipped = 0
    for filepath in list(SOLUTIONS_DIR.glob("*.*")):
        stem = filepath.stem  # "<id>-<slug>"
        ext = filepath.suffix
        parts = stem.split("-", 1)
        if len(parts) != 2:
            print(f"略過無法辨識的檔名：{filepath.name}")
            skipped += 1
            continue
        frontend_id, slug = parts

        info = metadata.get(frontend_id)
        if info is None or info["slug"] != slug:
            match = slug_lookup.get(slug)
            if match:
                frontend_id, info = match
            else:
                print(f"在 CSV 找不到對應資料，略過：{filepath.name}")
                skipped += 1
                continue

        primary_tag = sanitize(info["tags"][0]) if info["tags"] else "Uncategorized"
        target_dir = SOLUTIONS_DIR / primary_tag
        target_dir.mkdir(exist_ok=True)

        safe_title = sanitize(info["title"]).replace(" ", "-")
        new_name = f"{frontend_id}-{safe_title}-{info['difficulty']}{ext}"
        target_path = target_dir / new_name

        filepath.replace(target_path)
        moved += 1

    print(f"完成：分類 {moved} 個檔案，略過 {skipped} 個。")


if __name__ == "__main__":
    main()
