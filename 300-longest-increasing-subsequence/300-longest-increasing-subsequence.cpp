class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v;
        int n = nums.size();
        v.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(v.back()<nums[i])
                v.push_back(nums[i]);
            auto idx = lower_bound(v.begin(), v.end(), nums[i]);
            *idx = nums[i];
        }
        return v.size();
    }
};