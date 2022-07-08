class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        if(a[1]!=b[1])
            return a[1]<b[1];
        return a[2]<b[2];
    }
    
    int maxHeight(vector<vector<int>>& v) {
        int n = v.size();
        for(int i=0; i<n; i++){
            sort(v[i].begin(), v[i].end());
        }
        
        
        vector<int>dp(n);
        int ans = 0;
        sort(v.begin(), v.end(), comp);
        for(int i=n-1;i>=0;i--)
        {
            dp[i] = v[i][2];
            for(int j=i+1;j<n;j++)
            {
                if(v[i][0]<=v[j][0] and v[i][1]<=v[j][1] and v[i][2]<=v[j][2] )
                    dp[i] = max(dp[i], dp[j] + v[i][2]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};