class Solution {
public:
    int dp[366];
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        int n = days.size();
        int k = 0;
        return fun(days, costs, n, k);
    }
    
    int fun(vector<int>& days, vector<int>&costs, int n, int k)
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
        int y = k;
        while(y<n and days[y]<days[k]+30)
            y++;
        int c = costs[2] + fun(days, costs, n, y);
        return dp[k] = min({a, b, c});
        
    }
};