class Solution {
public:
    int dp[5001][2];
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return fun(0, 0, prices);
    }
    
    int fun(int i, int buy, vector<int>&prices)
    {
        if(i>=prices.size())
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        int buyStock = INT_MIN;
        int sellStock = INT_MIN;
        
        if(!buy)
        {
            buyStock = max(-prices[i] + fun(i+1, 1, prices), fun(i+1, 0, prices));
        }
        else
        {
            sellStock = max(prices[i] + fun(i+2, 0, prices), fun(i+1, 1, prices));
        }
        return dp[i][buy] = max(buyStock, sellStock);
    }
};