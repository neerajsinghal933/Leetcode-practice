class Solution {
public:
    int n, m;
    int findRotateSteps(string ring, string key) {
        n = ring.size();
        m = key.size();
        
        vector<vector<int>>dp(n, vector<int>(m, -1));
        vector<int>arr[26];
        for(int i=0;i<n;i++)
        {
            arr[ring[i]-'a'].push_back(i);
        }
        return fun(ring, 0, key, 0, arr, dp);
    }
    
    int fun(string &ring, int i, string &key, int j, vector<int>arr[], vector<vector<int>>&dp)
    {
        if(j==m)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans = INT_MAX;
        for(int x:arr[key[j]-'a'])
        {
            ans = min(ans, 1 + min(abs(i-x), n - abs(i-x)) + fun(ring, x, key, j+1, arr, dp));
        }
        return dp[i][j] = ans;
    }
};