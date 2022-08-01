class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        int mask = 0;
        fun(nums, 0, ans, mask);
        return res;
    }
    
    void fun(vector<int>&nums, int x, vector<int>ans, int &mask)
    {
        if(x==nums.size())
        {
            for(int i=0;i<nums.size();i++)
            {
                if(mask & (1<<i))
                    ans.push_back(nums[i]);
            }
            res.push_back(ans);
            return;
        }
        // ans.push_back(nums[x]);
        mask = mask | (1<<x);
        fun(nums, x+1, ans, mask);
        // ans.pop_back();
        mask = mask & ~(1<<x);
        fun(nums, x+1, ans, mask);
        
    }
};