class Solution {
public:
    set<vector<int>>st;
    
    void fun(vector<int>&nums, int idx, vector<int>temp)
    {
        if(idx==nums.size())
        {
            sort(temp.begin(), temp.end());
            st.insert(temp);
            return;
        }
        fun(nums, idx+1, temp);
        temp.push_back(nums[idx]);
        fun(nums, idx+1, temp);
        temp.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        fun(nums, 0, temp);
        for(auto x:st)
            res.push_back(x);
        return res;
    }
};