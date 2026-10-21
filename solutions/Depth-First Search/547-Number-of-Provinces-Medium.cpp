class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        set<int> v;
        queue<int> v1;
        int ans = 0;

        for (int i = 0; i < isConnected.size(); i++) {
            if (v.count(i)) continue;

            ans++;
            v1.push(i);

            while (!v1.empty()) {
                int n = v1.front();
                v1.pop();

                if (v.count(n)) continue;
                v.insert(n);

                for (int j = 0; j < isConnected[n].size(); j++) {
                    if (isConnected[n][j] == 1) {
                        v1.push(j);
                    }
                }
            }
        }

        return ans;
    }
};