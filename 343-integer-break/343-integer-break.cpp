class Solution {
public:
    int integerBreak(int n) {

// int dp[n + 1];
// for(int i = 0 ; i <=n ; i++) dp[i] = 0;
// dp[0] = 0;
// dp[1] = 1;
// for(int i = 2 ; i <= n ; i++){
// for(int j = i - 1; j >= 0; j--){
// dp[i] = max(dp[i] , max((i - j) * j, (i - j) * dp[j]));
// }
// }
// return dp[n];
//     }
        
        // vector<int>dp(n+1, 0);
        // dp[1] = 1;
        // for(int i=2;i<=n;i++)
        // {
        //     for(int j=i-1;j>=0;j--)
        //     {
        //         dp[i] = max(dp[i], max((i-j)*j, (i-j)*dp[j]));
        //     }
        // }
        // return dp[n];
        vector<int>dp(n+1, 0);
        dp[1] = 1;
        for(int i=2;i<=n;i++)
        {
            for(int j=i;j>=0;j--)
            {
                dp[i] = max(dp[i], max((i-j)*j, (i-j)*dp[j]));
            }
        }
        return dp[n];
    }


};