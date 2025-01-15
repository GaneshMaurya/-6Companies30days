class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<vector<int>> q;
        int t = 0;

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, t});
                }
            }
        }

        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();

            int r = curr[0];
            int c = curr[1];
            grid[r][c] = 2;
            t = curr[2];

            for (auto dir: dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                    q.push({nr, nc, t+1});
                    grid[nr][nc] = 2;
                }
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return t;
    }
};
