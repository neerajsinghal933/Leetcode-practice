class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int i=0;i<=n;i++)
        {
            dp[0][i]=1;
            dp[1][i]=1;
        }
        
        for(int i=2;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(s[j-1] == s[j-i] and dp[i-2][j-1]==1)
                    dp[i][j]=1;
            }
        }
        int i, j;
        for(i=n;i>=0;i--)
        {
            bool flag=false;
            for(j=n;j>=0;j--)
            {
                if(dp[i][j]==1)
                {
                    flag=true;
                    break;
                }
                
            }
            if(flag)
                break;
        }
        string ans = "";
        ans = s.substr(j-i, i);
        return ans;
    }
};