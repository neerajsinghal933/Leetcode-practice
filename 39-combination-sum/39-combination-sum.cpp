class Solution {
public:
    map<vector<int>, int>m;
    vector<vector<int>> combinationSum(vector<int>& coin, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        int n = coin.size();
        fun(coin, target, temp, res);
        
        return res;
    }
    
    void fun(vector<int>&coin, int t, vector<int>temp, vector<vector<int>>&res)
    {
        if(t==0)
        {
            sort(temp.begin(), temp.end());
            if(!m[temp])
            {
                m[temp] = 1;
                res.push_back(temp);
                               
            }
            return; 
        }
        for(int i=0;i<coin.size();i++)
        {
            if(t>=coin[i])
            {
                temp.push_back(coin[i]);
                fun(coin, t-coin[i], temp, res);
                temp.pop_back();
            }
            // else
            // {
            //     fun()
            // }
        }
    }
};