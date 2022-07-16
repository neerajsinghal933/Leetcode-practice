class Solution {
public:
    int dp[55][55][55];
    int n, m;
    int mod =  1e9+7;
    int findPaths(int M, int N, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        n=N;
        m=M;
       return dfs(maxMove, startRow, startColumn);
        // return dp[startRow][startColumn][maxMove];
    }
    
    int dfs(int move, int x, int y)
    {
        if(x<0 or y<0 or x>=m or y>=n)
            return 1;
        if(move<=0)
            return 0;
        if(dp[x][y][move]!=-1)
            return dp[x][y][move];
        long long up = dfs(move-1, x-1, y);
        long long down = dfs(move-1, x+1, y);
        long long left = dfs(move-1, x, y-1);
        long long right = dfs(move-1, x, y+1);
        return dp[x][y][move] = (((up%mod + down%mod)%mod + (left%mod + right%mod))%mod)%mod;
    }
};