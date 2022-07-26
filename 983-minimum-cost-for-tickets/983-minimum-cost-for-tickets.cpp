class Solution {
public:
    int dp[366];
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // vector<int>dp
        memset(dp, -1, sizeof(dp));
        int n = days.size();
        return fun(days, costs, n, 0);
    }
    
    int fun(vector<int>&days, vector<int>&costs, int n, int k)
    {
        if(k>=n)
            return 0;
        if(dp[k]!=-1)
            return dp[k];
        int a = costs[0] + fun(days, costs, n, k+1);
        int x = k;
        while(x<n and days[x]<days[k]+7)
            x++;
        int b = costs[1] + fun(days, costs, n, x);
        x = k;
        while(x<n and days[x]<days[k]+30)
            x++;
        int c = costs[2] + fun(days, costs, n, x);
        return dp[k] = min({a, b, c});
    }
};