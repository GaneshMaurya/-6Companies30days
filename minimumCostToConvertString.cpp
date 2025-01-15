class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> adjMat(26, vector<long long>(26, 1e9));
        for (int i=0; i<26; i++) {
            adjMat[i][i] = 0;
        }

        int e = original.size();
        for (int i=0; i<e; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            adjMat[u][v] = min(adjMat[u][v], cost[i]*1LL);
        }

        for (int k=0; k<26; k++) {
            for (int i=0; i<26; i++) {
                for (int j=0; j<26; j++) {
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
                }
            }
        }

        long long res = 0;
        int n = source.size();
        for (int i=0; i<n; i++) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (adjMat[u][v] == 1e9) {
                return -1;
            }
            res += adjMat[u][v];
        }

        return res;
    }
};
