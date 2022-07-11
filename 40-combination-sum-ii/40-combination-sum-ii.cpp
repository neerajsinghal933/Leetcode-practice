class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        sort(candidates.begin(), candidates.end(), greater<int>());
        fun(candidates, target, temp, res, candidates.size());
        return res;
    }
    
    void fun(vector<int>&coins, int t, vector<int>temp, vector<vector<int>>&res, int n)
    {
        if(n==0 or t==0)
        {
            if(t==0)
                res.push_back(temp);
            return;
        }
        if(t-coins[n-1]>=0)
        {
            temp.push_back(coins[n-1]);
             fun(coins, t-coins[n-1], temp, res, n-1);
            temp.pop_back();
        }  
        else
            return;
        int k;
        for(k=n-1;k>0;k--)
        {
            if(coins[k-1]==coins[k])
                continue;
            break;
        }
        fun(coins, t, temp, res, k);
        // if(t-coins[n-1]>=0)
        // {
        //     temp.push_back(coins[n-1]);
        //      fun(coins, t-coins[n-1], temp, res, k);
        //     temp.pop_back();
        // } 
        // if(t-coins[n-1]>=0)
        // {
        //     temp.push_back(coins[n-1]);
        //      fun(coins, t-coins[n-1], temp, res, k);
        // }           
        
    }
};