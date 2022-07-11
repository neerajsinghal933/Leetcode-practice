class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        dp[0] = nums[0];
        if(n==1)
            return nums[0];
        dp[1] = max(nums[0], nums[1]);
        if(n<=1)
            return dp[n];
        for(int i=2;i<n;i++)
        {
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        return max(dp[n-1], dp[n-2]);
    }
};