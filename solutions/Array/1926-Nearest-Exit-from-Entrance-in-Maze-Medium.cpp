class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        int dy[4] = {1, -1, 0, 0};
        int dx[4] = {0, 0, 1, -1};

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            steps++;
            while (sz--) {
                auto [y, x] = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int ny = y + dy[d], nx = x + dx[d];
                    if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
                    if (maze[ny][nx] == '+') continue;
                    if (ny == 0 || ny == m - 1 || nx == 0 || nx == n - 1)
                        return steps;
                    maze[ny][nx] = '+';
                    q.push({ny, nx});
                }
            }
        }
        return -1;
    }
};