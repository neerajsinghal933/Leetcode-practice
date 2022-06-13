class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return fun(prices, 0, 1, 2, dp);
        
    }
    
    int fun(vector<int>&v, int idx, bool buy, int k, vector<vector<vector<int>>>&dp)
    {
        if(idx>=v.size() or k==0)
            return 0;
        if(dp[idx][buy][k]!=-1)
            return dp[idx][buy][k];
        if(buy)
        {
            return dp[idx][buy][k] = max(-v[idx] + fun(v, idx+1, !buy, k, dp), fun(v, idx+1, buy, k, dp));
        }
        else
        {
            return dp[idx][buy][k] = max(v[idx] + fun(v, idx+1, !buy, k-1, dp), fun(v, idx+1, buy, k, dp));
        }
    }
};