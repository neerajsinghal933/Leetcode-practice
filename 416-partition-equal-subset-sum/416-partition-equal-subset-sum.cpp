class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1)
            return 0;
        sum /= 2;
        vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
        return fun(nums, sum, n, dp);
    }
    
    bool fun(vector<int>&nums, int k, int n, vector<vector<int>>&dp)
    {
        if(n==0)
        {
            if(k==0)
                return true;
            return false;
        }
        if(dp[n][k]!=-1)
            return dp[n][k];
        bool flag = false;
        flag = fun(nums, k, n-1, dp);
        if(k>=nums[n-1])
            flag = flag or fun(nums, k - nums[n-1], n-1, dp);
        return dp[n][k] = flag;
    }
};