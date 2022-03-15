class Solution {
public:
    int dp[1001][1001];
    string shortestCommonSupersequence(string s1, string s2) {
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
        int i=n, j=m;
        string res = "";
        while(i>0 and j>0)
        {
            if(s1[i-1]==s2[j-1])
            {
                res = s1[i-1] + res;
                i--;j--;
            }
            else if(dp[i-1][j] > dp[i][j-1])
            {
                res = s1[i-1] + res;
                i--;
            }
            else
            {
                res = s2[j-1] + res;
                j--;
            }
        }
        while(i>0)
        {
            res = s1[i-1]+res;
            i--;
        }
        while(j>0){
            res = s2[j-1]+res;
            j--;
        }
        return res;
    }
};