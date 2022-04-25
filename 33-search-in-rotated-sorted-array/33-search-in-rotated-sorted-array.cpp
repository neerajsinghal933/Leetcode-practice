class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0,r = nums.size()-1;
        int idx=-1;
        while(l<=r){
            int mid = (l+r)/2;
            if((mid-1<0 or nums[mid-1]>nums[mid]) and (mid+1==nums.size() or nums[mid]<nums[mid+1]))
            {
                idx = mid;
                break;
            }
            if(nums[mid]>nums.back())
                l = mid + 1;
            else
                r = mid - 1;
        }
        int n1 = fun(nums, 0, idx, target);
        int n2 = fun(nums, idx, nums.size()-1, target);
        if(n1!=-1)
            return n1;
        if(n2!=-1)
            return n2;
        return -1;
    }
    
    int  fun(vector<int>&nums, int i, int j, int t)
    {
        int ans = -1;
        while(i<=j)
        {
            int mid = (i+j)/2;
            if(nums[mid]==t)
                return mid;
            if(nums[mid]>t)
            {
                j=mid-1;
            }
            else
                i=mid+1;
        }
        return ans;
    }
};