class Solution {
public:
    set<vector<int>>st;
    vector<vector<int>> combinationSum(vector<int>& coin, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        int n = coin.size();
        fun(coin, target, temp, res, n);
        return res;
    }
    
    void fun(vector<int>&coin, int target, vector<int>temp, vector<vector<int>>&res, int n)
    {
        if(n==0 or target==0)
        {
            if(target==0)
                res.push_back(temp);
            return;
        }
        fun(coin, target, temp, res, n-1);
        if(coin[n-1]<=target)
        {
            temp.push_back(coin[n-1]);
            fun(coin, target-coin[n-1], temp, res, n);
        }
    }
};