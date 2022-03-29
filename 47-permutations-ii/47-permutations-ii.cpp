class Solution {
public:
    // vector<vector<int>>res;
    set<vector<int>>res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>temp;
        int n = nums.size();
        fun(nums, n, 0, temp);
        vector<vector<int>>v(res.begin(), res.end());
        return v;
    }
    
     void fun(vector<int>&nums, int n, int idx, vector<int>temp)
    {
        if(idx==n)
        {
            res.insert(nums);
            return;
        }
        for(int i=idx;i<n;i++)
        {
            swap(nums[i], nums[idx]);
            fun(nums, n, idx+1, temp);
            swap(nums[i], nums[idx]);
        }
    }
};