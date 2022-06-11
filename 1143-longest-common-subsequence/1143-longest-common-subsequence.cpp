class Solution {
public:
     int t[1001][1001];
    int lcs(string &a, string &b,int n,int m)
    {
        // if(n==0 || m==0)
        //     return t[n][m] = 0;
        if(n==0 or m==0)
            return 0;
        if(t[n][m]!=0)
            return t[n][m];
        if(a[n-1]==b[m-1])
            return t[n][m]=1+lcs(a,b,n-1,m-1);
        else
            return t[n][m]=max(lcs(a,b,n-1,m),lcs(a,b,n,m-1));
    }
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n=text1.size(),m=text2.size();
        memset(t,0,sizeof(t));
        return lcs(text1,text2,n,m);   
    }
};