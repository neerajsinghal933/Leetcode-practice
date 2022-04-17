class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, 1);
        for(int i=n-2;i>=0;i--)
            dp[i] = fun(nums, n, i, dp);
        return *max_element(dp.begin(), dp.end());
    }
    
    int fun(vector<int>&nums, int n, int i, vector<int>&dp)
    {
        int x = 0;
        for(int j=i+1;j<n;j++)
        {
            if(nums[j]>nums[i])
                x = max(x, dp[j]);
        }
        return x+1;
    }
};