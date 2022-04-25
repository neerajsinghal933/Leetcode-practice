class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if((mid-1<0 or nums[mid-1]>nums[mid]) and (mid+1==nums.size() or nums[mid]<nums[mid+1]))
                return nums[mid];
            if(nums[mid]>nums.back())
                s = mid+1;
            else
                e = mid-1;
        }
        return 0;
    }
};