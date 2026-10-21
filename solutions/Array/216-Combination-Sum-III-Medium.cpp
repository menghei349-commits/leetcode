class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;

    void dfs(int start, int k, int remain) {
        if (v.size() == k) {
            if (remain == 0) ans.push_back(v);
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (i > remain) break;
            v.push_back(i);
            dfs(i + 1, k, remain - i);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(1, k, n);
        return ans;
    }
};