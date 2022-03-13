class Solution {
public:
    // map<vector<int>, int>m;
    set<vector<int>>st;
    vector<vector<int>> combinationSum(vector<int>& coin, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        int n = coin.size();
        fun(coin, target, temp, res, n);
        
        return res;
    }
    
    void fun(vector<int>&coin, int t, vector<int> temp, vector<vector<int>>&res, int n)
    {
        if(t == 0 || n == 0)
        {
            if(t==0)
            {
                res.push_back(temp);
            }
            return;
        }
        fun(coin, t, temp, res, n-1);
        if(coin[n-1] <= t)
        {
            temp.push_back(coin[n-1]);
            fun(coin, t-coin[n-1], temp, res, n);
        }
//         if(t==0)
//         {
//             sort(temp.begin(), temp.end());
//             if(!st[temp])
//             {
//                 // m[temp] = 1;
//                 st.insert(temp);
//                 res.push_back(temp);
                               
//             }
//             return; 
//         }
//         for(int i=0;i<coin.size();i++)
//         {
//             if(t>=coin[i])
//             {
//                 temp.push_back(coin[i]);
//                 fun(coin, t-coin[i], temp, res);
//                 temp.pop_back();
//             }
//             // else
//             // {
//             //     fun()
//             // }
//         }
    }
};