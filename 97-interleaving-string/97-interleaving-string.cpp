class Solution {
public:
    int dp[101][101];
    
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.size();
        int b = s2.size();
        int c = s3.size();
        if(a+b!=c)
            return false;
        memset(dp, -1, sizeof(dp));
        return fun(s1, s2, s3, a, b, c);
    }
    
    bool fun(string& s1, string& s2, string& s3, int a, int b, int c)
    {
        if(c==0)
            return true;
        if(dp[a][b]!=-1)
            return dp[a][b];
        bool p = false, q = false;
        if(a-1>=0 and s1[a-1]==s3[c-1])
            p = fun(s1, s2, s3, a-1, b, c-1);
        if(b-1>=0 and s2[b-1] == s3[c-1])
            q = fun(s1, s2, s3, a, b-1, c-1);
        return dp[a][b] = p or q;
    }
};