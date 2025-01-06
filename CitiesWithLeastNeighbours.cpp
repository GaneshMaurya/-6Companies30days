class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dist) {
        vector<vector<int>> mat(n, vector<int>(n, INT_MAX));
        for (auto it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            mat[u][v] = wt;
            mat[v][u] = wt;
        }

        for (int i=0; i<n; i++) {
            mat[i][i] = 0;
        }

        for (int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (mat[i][k] == INT_MAX || mat[k][j] == INT_MAX) {
                        continue;
                    }
                    else {
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                }
            }
        }

        int len = INT_MAX;
        int ans = 0;
        for (int i=0; i<n; i++) {
            int temp = 0;
            for (int j=0; j<n; j++) {
                if (mat[i][j] <= dist) {
                    temp++;
                }
            }

            if (temp <= len) {
                len = temp;
                ans = i;
            }
        }

        return ans;
    }
};
