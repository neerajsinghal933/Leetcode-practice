class Solution {
public:
    int dp[100001][2];
    int maxProfit(vector<int>& prices, int fee) {
         int n = prices.size();
        memset(dp, -1, sizeof(dp));
        return fun(prices, 0, 1, fee);
    }
    
    int fun(vector<int>&v, int idx, bool buy, int fee)
    {
        if(idx>=v.size())
            return 0;
        if(dp[idx][buy]!=-1)
            return dp[idx][buy];
        // int buyStock = INT_MIN;
        // int sellStock = INT_MIN;
        if(buy)
        {
           return dp[idx][buy] = max(-(v[idx]+fee) + fun(v, idx+1, !buy, fee), fun(v, idx+1, buy, fee));
        }
        else
        {
            return dp[idx][buy] = max(v[idx]  + fun(v, idx+1, !buy, fee), fun(v, idx+1, buy, fee));
        }
    }
};