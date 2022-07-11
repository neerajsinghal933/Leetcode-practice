class Solution {
public:
    // int cnt = 0;
    int combinationSum4(vector<int>& nums, int target) {
        // for(int i=0;i<nums.size();i++)
        int n = nums.size();
        vector<int>dp(target+1, -1);
        fun(nums, target , dp);
        return dp[target];
    }
    
    int fun(vector<int>&nums, int t, vector<int>&dp)
    {
        if(t<=0)
        {
            return t==0?1:0;
        }
        if(dp[t]!=-1)
            return dp[t];
        int cnt = 0;
        for(int i=0;i<nums.size();i++)
        {
            cnt += fun(nums, t-nums[i], dp);
        }
        return dp[t] = cnt;
        // if(i==nums.size() or t<0)
        //     return;
        // if(t==0)
        // {
        //     // cout<<i<<" ";
        //     cnt++;return;
        // }
        // fun(nums, t, n-1);
        // if(t-nums[n-1]>=0)
        //     fun(nums, t-nums[n-1], n);
        // fun(nums, t, i+1);
    }
};