class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));
        return fun(prices, 0, 1, k, dp);
    }
    int fun(vector<int>&p, int idx, bool buy, int k, vector<vector<vector<int>>>&dp)
    {
        if(idx>=p.size() or k==0)
            return 0;
        if(dp[idx][buy][k]!=-1)
            return dp[idx][buy][k];
        if(buy)
        {
            return dp[idx][buy][k] = max(-p[idx] + fun(p, idx+1, !buy, k, dp), fun(p, idx+1, buy, k, dp));
            
        }
        else
        {
            return dp[idx][buy][k] = max(p[idx] + fun(p, idx+1, !buy, k-1, dp), fun(p, idx+1, buy, k, dp));
        }
    }
};