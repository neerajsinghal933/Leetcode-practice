class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int t = (sum + target) / 2;
        if(sum<target or (sum + target)%2==1 or sum<0 or t<0)
            return 0;
        sum = t;
        int n = nums.size();
        int cnt_zero = count(nums.begin(), nums.end(), 0);
        vector<vector<int>>dp(n+1, vector<int>(sum+1, 0));
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(nums[i-1]!=0 and nums[i-1]<=j)
                    dp[i][j] += dp[i-1][j-nums[i-1]];
            }
        }
        return pow(2, cnt_zero) * dp[n][sum];
    }
};