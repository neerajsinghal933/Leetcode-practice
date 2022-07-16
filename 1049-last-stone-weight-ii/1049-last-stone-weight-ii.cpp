class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        return fun(stones, sum);
    }
    
    int fun(vector<int>&v, int sum)
    {
        int n = v.size();
        vector<vector<bool>>dp(n+1, vector<bool>(sum+1, 0));
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(v[i-1]<=j)
                    dp[i][j] = dp[i][j] or dp[i-1][j-v[i-1]];
            }
        }
        int i;
        for(i=sum/2;i>=0;i--)
        {
            if(dp[n][i]==1)
                break;
        }
        return  sum - 2*i;
    }
};