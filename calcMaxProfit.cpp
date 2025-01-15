class Solution {
public:
    vector<vector<int>> memo;

    int solve(int ind, vector<int>& prices, int trans, int k) {
        int n = prices.size();
        if (ind >= n || trans >= 2*k+1) {
            return 0;
        }

        if (memo[ind][trans] != -1) {
            return memo[ind][trans];
        }

        int profit = 0;
        if (trans%2 == 0) {
            profit = max(-prices[ind] + solve(ind+1, prices, trans+1, k), solve(ind+1, prices, trans, k));
        }
        else {
            profit = max(prices[ind] + solve(ind+1, prices, trans+1, k), solve(ind+1, prices, trans, k));
        }

        return memo[ind][trans] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        memo.resize(n+1, vector<int>(2*k+1, -1));
        return solve(0, prices, 0, k);
    }
};

// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

//         for (int ind=n-1; ind>=0; ind--) {
//             for (int trans=2*k-1; trans>=0; trans--) {
//                 int profit = 0;
//                 if (trans%2 == 0) {
//                     profit = max(-prices[ind] + dp[ind+1][trans+1], dp[ind+1][trans]);
//                 }
//                 else {
//                     profit = max(prices[ind] + dp[ind+1][trans+1], dp[ind+1][trans]);
//                 }
//                 dp[ind][trans] = profit;
//             }
//         }

//         return dp[0][0];
//     }
// };
