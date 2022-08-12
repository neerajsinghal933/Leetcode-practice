class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // int curr = nums[0];
        int mx = nums[0];
        if(n==1)
            return true;
        for(int i=0;i<n;i++)
        {
            if(i>mx)
            {
                return false;
            }
            mx = max(mx, i+nums[i]);
            if(mx>=n-1)
                return true;
        }
        return 1;
    }
};