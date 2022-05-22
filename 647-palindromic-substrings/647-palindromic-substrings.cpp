class Solution {
public:
    int dp[1001][1001];
    int countSubstrings(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        // return func(0, n-1, s);
        int cnt = n;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(func(i, j, s))
                    cnt++;
            }
        }
        return cnt;
        
    }
    
    bool func(int i, int j, string &s)
    {
        if(i>j)
            return 1;
        // if(i==j)
        //     return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]!=s[j])
            return dp[i][j]=0;
        else 
        return dp[i][j] = func(i+1, j-1, s);
    }
};