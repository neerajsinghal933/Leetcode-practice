class Solution {
public:
    void fun(int k, int n, int i, vector<int>temp, vector<vector<int>>&res)
    {
        if(temp.size()==k && n==0)
        {
            res.push_back(temp);return;
        }
        if(n<0 || temp.size()>k || i>9) return;
        fun(k, n, i+1, temp, res);
        temp.push_back(i);
        fun(k, n-i, i+1, temp, res);
        // temp.pop_back();
        
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>temp;
        fun(k, n, 1, temp, res);
        return res;
    }
};