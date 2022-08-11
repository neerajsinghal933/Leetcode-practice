class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>>dp;
        int i=0;
        for(int i=0;i<ranges.size();i++)
        {
            int left=max(i-ranges[i],0);
            int right=min(i+ranges[i],n);
            dp.push_back({left,right});
        }
        sort(dp.begin(), dp.end());
        int curr = 0;
        int mx = 0;
        i=0;
        int cnt = 0;
        while(mx<n)
        {
            while(i<dp.size() and dp[i][0]<=mx)
            {
                curr = max(curr, dp[i][1]);
                i++;
            }
            if(curr<=mx)
                return -1;
            mx = curr;
            cnt++;
        }
        return cnt;
    }
};