class Solution {
public:
    vector<string> v = vector<string>(10), v1;

    vector<string> letterCombinations(string digits) {
        v[2] = "abc";
        v[3] = "def";
        v[4] = "ghi";
        v[5] = "jkl";
        v[6] = "mno";
        v[7] = "pqrs";
        v[8] = "tuv";
        v[9] = "wxyz";

        if (digits.empty()) return {};
        solve(digits, "", 0);
        return v1;
    }

    void solve(string s, string ans, int q){
        if (s.size() != ans.size()) {
            int d = s[q] - '0';
            for (int i = 0; i < v[d].size(); i++) {
                solve(s, ans + v[d][i], q + 1);
            }
        } else {
            v1.push_back(ans);
        }
    }
};