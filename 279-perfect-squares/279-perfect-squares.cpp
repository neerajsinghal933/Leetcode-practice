class Solution {
public:
    vector<int> dp;
    int helper(int n){
    if(n < 0){
        return INT_MAX;
    }
    if(n == 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int mi = INT_MAX;
    for(int i = 1; i*i <=n; i++){
        mi = min(helper(n - i*i),mi);
    }
    dp[n] = mi + 1;
    return mi + 1;
}

    int numSquares(int n) {
        for(int i = 0; i <= n; i++){
            dp.push_back(INT_MAX);
        }
        // return helper(n);
        
        dp[0] = 0;
        for(int i=1;i<=n;i++)
        {
            
            for(int j=1;j*j<=i;j++)
            {
                // if(i-j*j>=0)
                dp[i] = min(dp[i], dp[i-j*j]+1);    
            }
        }
        return dp[n];
    }
};