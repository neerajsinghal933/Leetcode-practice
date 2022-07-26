class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>a;
        vector<vector<int>>ans;
        fun(n, k, 1, a, ans);
        return ans;
    }
    
    void fun(int n, int k, int i, vector<int>&a, vector<vector<int>>&ans)
    {
        if(i>n or k==0)
        {
            if(k==0)
                ans.push_back(a);
            return;
        }
        fun(n, k, i+1, a, ans);
        a.push_back(i);
        fun(n, k-1, i+1, a, ans);
        a.pop_back();
    }
};