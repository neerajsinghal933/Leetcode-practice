class Solution {
public:
    vector<vector<int>>res;
    
    void fun(vector<int>&nums, int idx, vector<int>temp)
    {
        res.push_back(temp);
        if(idx>=nums.size())
        {
            // sort(temp.begin(), temp.end());
            // st.insert(temp);
            // res.push_back(temp);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx and nums[i]==nums[i-1])
                continue;
            
            temp.push_back(nums[i]);
            fun(nums,  i+ 1, temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int>temp;
        sort(nums.begin(), nums.end());
        fun(nums, 0, temp);
        // for(auto x:st)
        //     res.push_back(x);
        return res;
    }
};