class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr = nums[0];
        int n = nums.size();
        if(n==1)
            return true;
        int i=1;
        while(1)
        {
            if(curr<i)
                return false;
            curr = max(curr, i+nums[i]);
            i++;
            if(curr>=n-1)
                return true;
        }
        return false;
    }
};