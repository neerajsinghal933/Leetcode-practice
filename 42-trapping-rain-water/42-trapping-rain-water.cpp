class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int>dp(n);
        
        int curr = -1, ans = 0;
        for(int i=0;i<n;i++)
        {
            curr = max(curr, h[i]);
            dp[i] = curr - h[i];
        }
        
        curr = -1;
        for(int i=n-1;i>=0;i--)
        {
            curr = max(curr, h[i]);
            ans += min(dp[i], curr-h[i]);
        }
        return ans;
    }
};