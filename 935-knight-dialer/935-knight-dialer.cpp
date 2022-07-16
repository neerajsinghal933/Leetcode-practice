class Solution {
public:
    int mod = 1e9+7;
    int dp[4][3][5001];
    
    int dirX[8] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dirY[8] = {2, -2, 2, -2, 1, -1, 1, -1};
    
    int knightDialer(int n) {
        memset(dp, -1, sizeof(dp));
        long long ans = fun(3, 1, n-1);
        for(int i=1;i<=9;i++)
        {
            ans += fun((i-1)/3, (i-1)%3, n-1);
            ans %= mod;
        }
        return ans;
    }
    
    bool isSafe(int x, int y)
    {
        if(x<0 or x>3)
            return false;
        if(y<0 or y>2)
            return false;
        if(x==3 and y!=1)
            return false;
        return true;
    }
    
    int fun(int x, int y, int n)
    {
        if(!isSafe(x, y))
            return 0;
        if(n==0)
            return 1;
        if(dp[x][y][n]!=-1)
            return dp[x][y][n];
        long long ans = 0;
        for(int i=0;i<8;i++)
        {
            ans += fun(x+dirX[i], y+dirY[i], n-1);
            ans %= mod;
        }
        return dp[x][y][n] = ans;
        
    }
};