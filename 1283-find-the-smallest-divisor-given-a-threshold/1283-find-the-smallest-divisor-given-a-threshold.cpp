class Solution {
public:
    bool check(vector<int>&nums, int th, int mid)
    {
        int cnt = 0;
        for(int x:nums)
        {
            cnt += ceil(x/(double)mid);
        }
        if(cnt<=th)
            return true;
        return false;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans;
        while(low<=high)
        {
            int mid = (low + high)/2;
            if(check(nums, threshold, mid)==true)
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};