class Solution {
public:
   
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        unordered_map<int, int>m;
        for(int x:nums)
            m[x]++;
        vector<int>temp;
        fun(nums.size(), ans, m, temp);
        return ans;
    }
    
    void fun(int idx, vector<vector<int>>&ans, unordered_map<int, int>&m, vector<int>&temp)
    {
        if(idx==0)
        {
            ans.push_back(temp);
            return;
        }
        for(auto &it:m)
        {
            if(it.second==0)
                continue;
            it.second--;
            temp.push_back(it.first);
            fun(idx-1, ans, m, temp);
            temp.pop_back();
            it.second++;
        }
    }
};