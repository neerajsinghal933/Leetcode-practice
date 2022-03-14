class Solution {
public:
    int dp[1001][1001];
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        // vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        memset(dp, 0, sizeof(dp));
        // return fun(s1, s2, n, m);
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    
    int fun(string s1, string s2, int n, int m)
    {
        if(n==0 or m==0)
            return 0;
        if(dp[n][m] != -1)
            return dp[n][m];
        if(s1[n-1]==s2[m-1])
            return dp[n][m] = 1 + fun(s1, s2, n-1, m-1);
        else
            return dp[n][m] = max(fun(s1, s2, n-1, m), fun(s1, s2, n, m-1));
    }
};