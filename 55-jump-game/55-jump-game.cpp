class Solution {
public:
    vector<int>dp;
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1);
        fun(nums, 0);
        return dp[0];
    }
    
    int fun(vector<int>&nums, int i)
    {
        int n = nums.size();
        if(i>=n-1)
            return true;
        if(dp[i]!=-1)
            return dp[i];
        bool flag = false;
        for(int x=1;x<=nums[i];x++)
        {
            if(fun(nums, i+x))
            {
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
};