class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0, j=0;
        int curr = 0;
        int n = nums.size();
        int ans = INT_MAX;
        while(j<n)
        {
            
            curr += nums[j];
            while(curr>=target)
            {
                ans = min(ans, j-i+1);
                curr -= nums[i];
                i++;
            }
            j++;
        }
        return ans==INT_MAX?0:ans;
    }
};