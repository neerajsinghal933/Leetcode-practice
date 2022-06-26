class Solution {
public:
    int countHousePlacements(int n) {
        vector<long long>dp(n+1);
        int mod = 1e9+7;
        if(n==1)
            return 4;
        if(n==2)
            return 9;
        dp[1]=2;
        dp[2] = 3;
        for(int i=3;i<=n;i++)
            dp[i] = (dp[i-1] + dp[i-2])%mod;
        long long  ans = 1;
        // for(int i=1;i<=dp[n];i++)
        //     ans = (ans*dp[n])%mod;
        return (dp[n]*dp[n])%mod;
        // return ans;
    }
};