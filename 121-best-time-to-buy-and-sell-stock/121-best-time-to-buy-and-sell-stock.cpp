class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int ele = prices[0];
        for(int i=1;i<n;i++)
        {
            ans = max(ans, prices[i]-ele);
            ele = min(ele, prices[i]);
        }
        return ans;
    }
};