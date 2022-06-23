class Solution {
public:
    int dp[1001][1001];
    
    bool fun(string &a, string &b, string &c, int n, int m, int sz)
    {
        if(sz==0)
        return true;
        if(dp[n][m] != -1)
            return dp[n][m];
        bool p = false, q = false;
        if(n-1>=0 and a[n-1]==c[sz-1])
            p = fun(a, b, c, n-1, m, sz-1);
        if(m-1>=0 and b[m-1]==c[sz-1])
            q = fun(a, b, c, n, m-1, sz-1);
        return dp[n][m] = p or q;
    }
    
    bool isInterleave(string A, string B, string C) {
         int n = A.size();
        int m = B.size();
        int sz = C.size();
        
        if(n+m!=sz)
        return 0;
        dp[n][m];
        memset(dp, -1, sizeof(dp));
        return fun(A, B, C, n, m, sz);
    }
};