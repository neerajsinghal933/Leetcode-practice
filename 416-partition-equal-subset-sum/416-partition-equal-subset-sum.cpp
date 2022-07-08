class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1)
            return 0;
        sum /= 2;
        return fun(nums, sum, n);
    }
    
    bool fun(vector<int>&nums, int k, int n)
    {
        vector<vector<bool>>dp(n+1, vector<bool>(k+1, false));
        for(int i=0;i<=n;i++)
            dp[i][0] = true;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(nums[i-1]<=j)
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];// or dp[i-1][nums[i-1]-j];
            }
        }
        return dp[n][k];
    }
};