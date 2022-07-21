class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int>m;
        for(int x:nums)
            m[x]++;
        vector<int>temp;
        fun(m, nums.size(), temp);
        return ans;
        
    }
    
    void fun(unordered_map<int, int>&m, int n, vector<int>&temp)
    {
        if(n==0)
        {
            ans.push_back(temp);
            return;
        }
        for(auto &it:m)
        {
            if(it.second<=0)
                continue;
            it.second--;
            temp.push_back(it.first);
            fun(m, n-1, temp);
            temp.pop_back();
            it.second++;
        }
    }
};