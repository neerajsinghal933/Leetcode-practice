class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, 0));
        for(int i=0;i<=amount;i++)
            dp[0][i] = INT_MAX-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(j>=coins[i-1])
                    dp[i][j] = min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][amount]==INT_MAX-1?-1:dp[n][amount];
    }
};