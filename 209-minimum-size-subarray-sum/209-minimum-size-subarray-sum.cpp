class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0, j=0;
        int n =nums.size();
        int curr = 0;
        int ans = INT_MAX;
        while(i<n)
        {
            curr += nums[i];
            while(curr>=target)
            {
                ans = min(ans, i-j+1);
                curr -= nums[j];
                j++;
            }
            i++;
        }
        return ans==INT_MAX?0:ans;
    }
};