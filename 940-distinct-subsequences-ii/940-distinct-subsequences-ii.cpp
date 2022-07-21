class Solution {
public:
    int distinctSubseqII(string s) {
        int n  = s.size();
        int mod = 1e9+7;
        vector<int>v(256, -1);
        int dp[n+1];
        dp[0] = 1;
        for(int i=1;i<=n;i++)
        {
            dp[i] = (dp[i-1]%mod + dp[i-1]%mod)%mod;
            if(v[s[i-1]]!=-1)
                dp[i] = (dp[i] - dp[v[s[i-1]]] + mod)%mod;
            v[s[i-1]] = (i-1);
        }
        return dp[n]-1;
    }
};