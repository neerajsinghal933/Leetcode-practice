class Solution {
public:
    int ans = 0;
    int fun(string& s, int i, int j, vector<vector<int>>&dp, int n1, int n2)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i>j)
            return dp[i][j]=0;
        if(i==j)
            return dp[i][j]=1;
        if(s[i]==s[j])
        {
            dp[i][j] = 2 + fun(s, i+1, j-1, dp, n1, n2);
            if(i<n1 and j>=n1)
                ans = max(ans, dp[i][j]);
            return dp[i][j];
        }
        return dp[i][j] = max(fun(s, i+1, j, dp, n1, n2), fun(s, i, j-1, dp, n1, n2));
    }
    int longestPalindrome(string s1, string s2) {
        string s = s1+s2;
        int n = s.size();
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        ans = 0;
        fun(s, 0, n-1, dp, n1, n2);
        return ans;
    }
};