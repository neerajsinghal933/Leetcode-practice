class Solution {
public:
    int dp[1001][1001];
    int countSubstrings(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        int cnt = n;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(fun(i,j,s))
                    cnt++;
            }
        }
        return cnt;
    }
    
    bool fun(int i, int j, string &s)
    {
        if(i>j)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]!=s[j])
            return dp[i][j] = 0;
        return dp[i][j] = fun(i+1, j-1, s);
        //     return true;
        // return false;
    }
};