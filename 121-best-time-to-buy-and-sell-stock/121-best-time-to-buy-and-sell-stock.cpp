class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int mini = prices[0];
        for(int i=0;i<n;i++)
        {
            if(prices[i]>mini)
                ans = max(ans, prices[i]-mini);
            else
                mini = min(mini, prices[i]);
        }
        return ans;
    }
};