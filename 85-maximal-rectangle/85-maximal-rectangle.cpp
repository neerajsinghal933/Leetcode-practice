class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // int mx = 0;
        vector<vector<int>>dp(n, vector<int>(m, 0));
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0')
                    continue;
                if(i==0)
                {
                    dp[i][j] = 1;
                }
                else
                    dp[i][j] = 1 + dp[i-1][j];
                int k=j;
                int curr = dp[i][j];
                while(k>=0 and dp[i][k]!=0)
                {
                    curr = min(curr, dp[i][k]);
                    ans = max(ans, curr * (j-k+1));
                    k--;
                }
            }
        }
        return ans;
    }
};