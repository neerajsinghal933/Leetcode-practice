class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        int n = nums.size();
        fun(nums, n, 0, temp);
        return ans;
        
    }
    
    void fun(vector<int>&nums, int n, int idx, vector<int>&temp)
    {
        if(idx==n)
        {
            ans.push_back(nums);
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