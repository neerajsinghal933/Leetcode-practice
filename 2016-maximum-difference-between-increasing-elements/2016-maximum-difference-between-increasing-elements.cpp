class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int mini = nums[0];
        int ans = INT_MIN;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
                ans = max(ans, nums[i]-mini);
            else
                mini = min(mini, nums[i]);
        }
        return ans==INT_MIN?-1:ans;
    }
};