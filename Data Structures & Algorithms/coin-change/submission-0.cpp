#include<cstring>
class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& coins, int amount, int i, int n) {
        if(amount == 0) {
            return 0;
        }

        if(amount < 0) {
            return 1e9;
        }

        if(i == n) {
            return 1e9;
        }

        if(dp[i][amount] != -1) {
            return dp[i][amount];
        }

        int take = 1 + solve(coins, amount - coins[i], i, n);
        int skip = solve(coins, amount, i + 1, n);

        return dp[i][amount] = min(take, skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.assign(n + 1, vector<int>(amount + 1, -1));
        int ans = solve(coins, amount, 0, n);

        return ans >= 1e9 ? -1 : ans;
    }
};
