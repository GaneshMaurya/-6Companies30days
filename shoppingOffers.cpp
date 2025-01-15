class Solution {
public:
    map<vector<int>, int> memo;
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        if (memo.find(needs) != memo.end()) {
            return memo[needs];
        }

        int ans = 0;
        for (int i=0; i<n; i++) {
            ans += needs[i]*price[i];
        }

        for (int i=0; i<special.size(); i++) {
            bool valid = true;
            for (int j=0; j<n; j++) {
                if (needs[j] < special[i][j]) {
                    valid = false;
                    break;
                }
            }

            if (valid == true) {
                for (int j=0; j<n; j++) {
                    needs[j] -= special[i][j];
                }

                int temp = special[i].back() + solve(price, special, needs);
                ans = min(ans, temp);

                for (int j=0; j<n; j++) {
                    needs[j] += special[i][j];
                }
            }
        }

        return memo[needs] = ans;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return solve(price, special, needs);
    }
};
