class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
    vector<int>dp(n, 0);
    if(n==0)
        return 0;
    int r = p[n-1];
    int l = p[0];

    for(int i=n-2;i>=0;i--)
    {
        if(p[i] > r)
            r = p[i];
        dp[i] = max(dp[i+1], r - p[i]);
    }

    for(int i=1;i<n;i++)
    {
        if(l > p[i])
            l = p[i];
        dp[i] = max(dp[i-1], dp[i] + p[i] - l);
    }
    return dp[n-1];
        
    }
};