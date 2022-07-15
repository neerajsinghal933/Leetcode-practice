class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        int ans =  0;
        for(int i=0;i<n;i++)
        {
            if(i>0)
            {
                for(int j=0;j<m;j++)
                {
                    if(v[i][j])
                        v[i][j] += v[i-1][j];
                }
            }
            vector<int>t(v[i].begin(), v[i].end());
            sort(t.begin(), t.end(), greater<int>());
            int h = INT_MAX;
            for(int k=0;k<m;k++)
            {
                h = min(h, t[k]);
                if(h==0)
                    continue;
                ans = max(ans, h*(k+1));
            }
        }
        return ans;
    }
};