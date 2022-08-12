class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return  fun(s, p, n, m, dp);
    }
    
    int fun(string &s, string& p, int i, int j, vector<vector<int>>&dp)
    {
        if(i==0 and j==0)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(j==0)
        {
            return dp[i][j] = 0;
        }
        if(i==0)
        {
            if(p[j-1]!='*')
            {
                return dp[i][j] = 0;
            }
            return dp[i][j] = fun(s, p, i, j-1, dp);
        }
        if(s[i-1]==p[j-1] or p[j-1]=='?')
            return dp[i][j] = fun(s, p, i-1, j-1, dp);
        if(p[j-1]=='*')
            return dp[i][j] = fun(s, p, i-1, j, dp) or fun(s, p, i, j-1, dp);
        return dp[i][j] = 0;
    }
};