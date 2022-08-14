class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int>dp(n+1, 0);
        dp[0] = 1;
        for(int i=0;i<n;i++)
        {
            string t = "";
            for(int j=i;j<n;j++)
            {
                t += s[j];
                if(find(wordDict.begin(), wordDict.end(), t)!=wordDict.end() and dp[i]==1)
                {
                    dp[j+1] = 1;
                    // i=j+1;
                    // cout<<i<<" ";
                    // break;
                }
            }
        }
        return dp[n];
    }
};