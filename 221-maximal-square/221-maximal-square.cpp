class Solution {
public:
    int maximalSquare(vector<vector<char>>& v) {
        int n = v.size();
        int m = v[0].size();
        
        vector<vector<int>>dp(n, vector<int>(m, 0));
        int cnt = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 or j==0)
                {
                    if(v[i][j]=='1')
                        dp[i][j] = 1;
                    // continue;
                }
                else
                {
                    if(v[i][j]=='1')
                    {
                        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    }
                }
                cnt = max(cnt, dp[i][j]);
            }
        }
        return cnt*cnt;
    }
};