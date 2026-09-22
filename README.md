# LeetCode 自動抓題工具

抓取自己 LeetCode 帳號的解題資料，並依主題分類保存程式碼。

## 功能

- 抓取已解出的題目清單，輸出成 `solved_problems.csv`（題號、標題、難度、標籤）
- 抓取每題最新一次 Accepted 的程式碼，依「第一個 topic tag」自動分類存到 `solutions/<主題>/` 資料夾
- 新的主題（tag）會自動建立資料夾，不需要手動維護分類清單

## 事前準備

1. 安裝套件：

   ```
   pip install -r requirements.txt
   ```

2. 取得登入用的 cookie：
   - 瀏覽器登入 [leetcode.com](https://leetcode.com)
   - 打開 DevTools（F12）→ **應用程式 (Application)** → 左側 **Cookie** → 選 `https://leetcode.com`
   - 複製以下兩個值：
     - `LEETCODE_SESSION`
     - `csrftoken`

3. 複製設定檔並填入 cookie：

   ```
   copy config.example.json config.json
   ```

   打開 `config.json`，把剛剛複製的值貼進去：

   ```json
   {
     "leetcode_session": "貼上 LEETCODE_SESSION 的值",
     "csrf_token": "貼上 csrftoken 的值"
   }
   ```

   > `config.json` 已列在 `.gitignore`，不會被上傳到 GitHub。**不要分享這個檔案**，裡面的 cookie 等同於你的登入憑證。

## 使用方式

### 抓取資料 + 分類程式碼

```
python leetcode_scraper.py
```

會依序：
1. 確認登入狀態
2. 抓取所有題目的解題狀態，寫入 `solved_problems.csv`
3. 抓取所有 Accepted 提交紀錄，把每題最新一次的程式碼依主題分類存到 `solutions/<主題>/題號-標題-難度.副檔名`

### 只重新整理既有的 solutions 資料夾

如果 `solutions/` 內已經有扁平的程式碼檔案（沒有分類），可以單獨跑：

```
python organize_solutions.py
```

它會讀取 `solved_problems.csv` 的標籤資訊，把 `solutions/` 內的檔案搬進對應的主題資料夾。一般情況不需要用到，因為 `leetcode_scraper.py` 執行時就會直接分類存放。

## 輸出範例

```
solutions/
├── Array/
│   └── 238-Product-of-Array-Except-Self-Medium.cpp
├── Two Pointers/
│   └── 345-Reverse-Vowels-of-a-String-Easy.cpp
└── Math/
    └── 9-Palindrome-Number-Easy.cpp
```

## GitHub Actions 定期自動同步

`.github/workflows/leetcode-sync.yml` 會每天自動執行腳本，若有新解出的題目就自動 commit + push。

### 設定 Secrets

到 repo 頁面 **Settings → Secrets and variables → Actions → New repository secret**，新增兩組：

| Secret 名稱 | 值 |
| --- | --- |
| `LEETCODE_SESSION` | 你的 `LEETCODE_SESSION` cookie 值 |
| `LEETCODE_CSRF_TOKEN` | 你的 `csrftoken` cookie 值 |

Workflow 執行時會用這兩個 secrets 在 runner 上臨時產生 `config.json`，跑完就刪除，不會留在 repo 或 log 裡。

### 執行時機

- 預設排程：每天 UTC 14:00（台灣時間 22:00），可自行修改 workflow 檔案裡的 cron 設定
- 也可以到 **Actions → Sync LeetCode Solutions → Run workflow** 手動觸發一次

### 注意

- `LEETCODE_SESSION` 過期後（通常幾週），排程會因為登入失敗而執行失敗。GitHub 預設會寄信通知 repo 擁有者排程失敗，屆時回瀏覽器重新複製 cookie，更新對應的 Secret 值即可
- Push 用的是 GitHub Actions 自動提供的 `GITHUB_TOKEN`，不需要額外設定個人 PAT

## 注意事項

- `LEETCODE_SESSION` 通常幾週後會過期，重新執行若出現「登入失敗」訊息，回瀏覽器重新複製 cookie 貼回 `config.json` 即可
- 抓取過程中程式會自動加入延遲，避免請求過快被 LeetCode 限速；題目數量多時請耐心等待
- 每題只會保存**最新一次** Accepted 的程式碼，同一題若有多次通過的提交，舊的版本不會保留
