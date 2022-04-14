class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr = nums[0];
        if(nums.size()==1)
            return true;
        int n = nums.size();
        int i = 1;
        while(1)
        {
            if(curr < i)
                return false;
            curr = max(curr, i+nums[i]);
            i++;
            if(curr >= n-1)
                return true;
        }
        return 0;
    }
};