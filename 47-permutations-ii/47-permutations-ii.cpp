class Solution {
public:
    map<vector<int>, int>m;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        fun(nums, 0, ans);
        return ans;
    }
    
    void fun(vector<int>&nums, int idx, vector<vector<int>>&ans)
    {
        if(idx==nums.size())
        {
            if(m[nums]==0)
            {
                m[nums] = 1;
                ans.push_back(nums);
            }
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[i], nums[idx]);
            fun(nums, idx+1, ans);
            swap(nums[i], nums[idx]);
        }
    }
};