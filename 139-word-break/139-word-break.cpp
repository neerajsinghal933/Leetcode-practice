class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        dp[n] = 1;
        for(int i=n-1;i>=0;i--)
        {
            string temp = "";
            for(int k=i; k<n; k++)
            {
                temp += s[k];
                auto it = find(wordDict.begin(), wordDict.end(), temp);
                if(it!=wordDict.end() and dp[k+1]==1)
                    dp[i] = 1;
            }
        }
        return dp[0];
    }
};