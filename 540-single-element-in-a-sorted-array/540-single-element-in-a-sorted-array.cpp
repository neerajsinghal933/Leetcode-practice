class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0;
        int e = nums.size()-1;
        int n = nums.size();
        
        if(e==0)
            return nums[0];
        if(nums[0]!=nums[1])
            return nums[0];
        if(nums[n-2]!=nums[n-1])
            return nums[n-1];
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(nums[mid]!=nums[mid-1] and nums[mid]!=nums[mid+1])
                return nums[mid];
            if((mid%2==0 and nums[mid]==nums[mid+1]) or (mid%2==1 and nums[mid]==nums[mid-1]))
                s = mid+1;
            else
                e = mid-1;
        }
        return -1;
    }
};