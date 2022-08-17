class Solution {
public:
    
    int fun(vector<int>&nums, int k)
    {
        map<int, int>mp;
        int cnt = 0;
        int n = nums.size();
        int i=0, j=0;
        while(i<n)
        {
            mp[nums[i]]++;
            while(mp.size()>k)
            {
                mp[nums[j]]--;
                if(mp[nums[j]]==0)
                    mp.erase(nums[j]);
                j++;
            }
            // if(mp.size()==k)
                cnt+= (i-j+1);
            i++;
        }
        return cnt;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums, k) - fun(nums, k-1);
    }
};