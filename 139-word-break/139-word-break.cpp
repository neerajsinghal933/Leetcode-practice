class Solution {
public:
    bool wordBreak(string s, vector<string>& v) {
        int n = s.size();
        vector<bool>dp(n+1, false);
        dp[n] = 1;
        for(int i=n-1;i>=0;i--)
        {
            string t = "";
            for(int k=i;k<n;k++)
            {
                t += s[k];
                if(find(v.begin(), v.end(), t)!=v.end() and dp[k+1]==1)
                    dp[i] = 1;
            }
        }
        return dp[0];
    }
};