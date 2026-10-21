class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int> v;
        queue<int> v1;

        v1.push(0);

        while (!v1.empty()) {
            int n = v1.front();
            v1.pop();

            if (v.count(n)) continue;
            v.insert(n);

            for (int i = 0; i < rooms[n].size(); i++) {
                v1.push(rooms[n][i]);
            }
        }

        return v.size() == rooms.size();
    }
};