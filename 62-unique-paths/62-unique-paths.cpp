class Solution {
public:
    int uniquePaths(int n, int m) {
        int dp[n+1][m+1];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i==1 or j==1)
                    dp[i][j] = 1;
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }
};