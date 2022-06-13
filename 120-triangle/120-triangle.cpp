class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
        int n = v.size();
        for(int i=1;i<n;i++)
        {
            // cout<<"k";
            for(int j=0;j<v[i].size();j++)
            {
                int t = INT_MAX;
                if(j<v[i-1].size())
                    t = v[i-1][j];
                if(j-1>=0)
                {
                    // cout<<"n";
                    t = min(t, v[i-1][j-1]);
                }
                v[i][j] += t;
            }
        }
        // return 0;
        return *min_element(v[n-1].begin(), v[n-1].end());
    }
};