class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for (int y = 0; y < m; y++)
            for (int x = 0; x < n; x++)
                if (grid[y][x] == 2) solve(grid, y, x, 2);

        int ans = 2;
        for (auto& it : grid)
            for (int v : it) {
                if (v == 1) return -1;
                ans = max(ans, v);
            }
        return ans - 2;
    }

    void solve(vector<vector<int>>& grid, int y, int x, int time) {
        if (y < 0 || x < 0 || y >= grid.size() || x >= grid[0].size()) return;
        if (grid[y][x] == 0) return;
        if (grid[y][x] > 1 && grid[y][x] < time) return;

        grid[y][x] = time;
        solve(grid, y + 1, x, time + 1);
        solve(grid, y - 1, x, time + 1);
        solve(grid, y, x + 1, time + 1);
        solve(grid, y, x - 1, time + 1);
    }
};