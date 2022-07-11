class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        vector<int>first(nums.begin(), nums.end()-1);
        vector<int>second(nums.begin()+1, nums.end());
        return max(fun(first), fun(second));
    }
    
    int fun(vector<int>&v)
    {
        int n = v.size();
        if(n==1)
            return v[0];
        vector<int>dp(n);
        dp[0] = v[0];
        dp[1] = max(v[0], v[1]);
        for(int i=2;i<n;i++)
            dp[i] = max(dp[i-1], v[i] + dp[i-2]);
        return max(dp[n-1], dp[n-2]);
    }
};