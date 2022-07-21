class Solution {
public:
    map<vector<int>, int>m;
    void fun(vector<int>&nums, int idx, vector<vector<int>>&ans)
    {
        if(idx==nums.size())
        {
            if(!m[nums])
            {
                ans.push_back(nums);
                m[nums]++;
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
    
    vector<vector<int>> permuteUnique(vector<int>& ar) {
      
        vector<vector<int>>ans;
        fun(ar, 0, ans);
        return ans;
    }
};