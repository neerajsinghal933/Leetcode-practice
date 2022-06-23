class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(1001, 1));
        int ans = 2;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff = nums[i]-nums[j] + 500;
                dp[i][diff] = max(dp[i][diff], 1 + dp[j][diff]);
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};