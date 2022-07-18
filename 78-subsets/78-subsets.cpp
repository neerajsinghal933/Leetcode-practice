class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        fun(nums, 0, ans);
        return res;
    }
    
    void fun(vector<int>&nums, int x, vector<int>ans)
    {
        if(x==nums.size())
        {
            res.push_back(ans);
            return;
        }
        
        fun(nums, x+1, ans);
        ans.push_back(nums[x]);
        fun(nums, x+1, ans);
    }
};