class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = INT_MIN;
        if(n==1)
            return 0;
        for(int i=1;i<n;i++)
            ans = max(ans, nums[i] - nums[i-1]);
        return ans;
    }
};