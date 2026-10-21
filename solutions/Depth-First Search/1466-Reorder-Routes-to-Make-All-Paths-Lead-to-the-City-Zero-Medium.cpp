class Solution {
public:
    int ans = 0;
    vector<vector<pair<int, int>>> v;

    void solve(int now, int parent) {
        for (auto& it : v[now]) {
            if (it.first != parent) {
                ans += it.second;
                solve(it.first, now);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        v.resize(n);
        for (auto& c : connections) {
            v[c[0]].push_back({c[1], 1});
            v[c[1]].push_back({c[0], 0});
        }
        solve(0, -1);
        return ans;
    }
};