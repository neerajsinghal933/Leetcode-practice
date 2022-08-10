class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        fun(nums, temp, 0);
        return res;
    }
    
    void fun(vector<int>&nums, vector<int>t, int i)
    {
        if(i==nums.size())
        {
            res.push_back(t);
            return;
        }
        fun(nums, t, i+1);
        t.push_back(nums[i]);
        fun(nums, t, i+1);
    }
};