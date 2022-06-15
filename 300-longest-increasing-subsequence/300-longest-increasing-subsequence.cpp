class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v;
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(v.back()<nums[i])
                v.push_back(nums[i]);
            else
            {
                auto idx = lower_bound(v.begin(), v.end(), nums[i]);
                *idx = nums[i];
            }
        }
        return v.size();
    }
};