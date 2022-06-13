class Solution {
public:
    int dp[5001][2];
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return fun(prices, 0, 1);
    }
    
    int fun(vector<int>&v, int idx, bool buy)
    {
        if(idx>=v.size())
            return 0;
        if(dp[idx][buy]!=-1)
            return dp[idx][buy];
        int buyStock = INT_MIN;
        int sellStock = INT_MIN;
        if(buy)
        {
            buyStock = max(-v[idx] + fun(v, idx+1, !buy), fun(v, idx+1, buy));
        }
        else
        {
            sellStock = max(v[idx] + fun(v, idx+2, !buy), fun(v, idx+1, buy));
        }
        return dp[idx][buy] = max(buyStock, sellStock);
    }
};