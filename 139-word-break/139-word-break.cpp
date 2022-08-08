class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int>dp(n+1);
        dp[n] = 1;
        for(int i=n-1;i>=0;i--)
        {
            string t = "";
            for(int j=i;j<n;j++)
            {
                t += s[j];
                if(find(wordDict.begin(), wordDict.end(), t)!=wordDict.end() and dp[j+1])
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[0];
    }
};