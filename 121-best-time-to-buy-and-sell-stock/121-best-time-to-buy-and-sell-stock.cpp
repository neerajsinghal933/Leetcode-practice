class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int ans = 0;
        int max_ele = v[n-1];
        for(int i=n-2;i>=0;i--)
        {
            max_ele = max(v[i], max_ele);
            ans = max(ans, max_ele - v[i]);
        }
        return ans;
    }
};