class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> v;
    vector<double> ans;

    void solve(string now, string target, double cur, unordered_set<string>& vis, double& res) {
        if (now == target) {
            res = cur;
            return;
        }
        vis.insert(now);
        for (auto& it : v[now]) {
            if (!vis.count(it.first)) {
                solve(it.first, target, cur * it.second, vis, res);
            }
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            v[equations[i][0]].push_back({equations[i][1], values[i]});
            v[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        for (auto& q : queries) {
            if (!v.count(q[0]) || !v.count(q[1])) {
                ans.push_back(-1.0);
            } else {
                double res = -1.0;
                unordered_set<string> vis;
                solve(q[0], q[1], 1.0, vis, res);
                ans.push_back(res);
            }
        }
        return ans;
    }
};