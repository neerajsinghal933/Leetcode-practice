class Solution {
public:
    int dp[101][101];
    int fun(int rodStart, int rodEnd, vector<int>&cuts, int s, int e)
    {
        if(s>e)
            return 0;
        if(dp[s][e]!=-1)
            return dp[s][e];
        int ans = INT_MAX;
        for(int i=s;i<=e;i++)
        {
            int l = fun(rodStart, cuts[i], cuts, s, i-1);
            int r = fun(cuts[i], rodEnd, cuts, i+1, e);
            int curr_cost = (rodEnd-  rodStart) + l + r;
            ans = min(ans, curr_cost);
        }
        return dp[s][e] = ans;
    }
    
    
    int minCost(int n, vector<int>& cuts) {
        int sz = cuts.size();
        sort(cuts.begin(), cuts.end());
        memset(dp, -1, sizeof(dp));
        return fun(0, n, cuts, 0, cuts.size()-1);
        
    }
};