class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = 0;
        vector<pair<int, int>>v;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(img2[i][j])
                    v.push_back({i, j});
            }
        }
        for(int vs=-n+1;vs<n;vs++)
        {
            for(int hs=-n+1;hs<n;hs++)
            {
                vector<vector<int>>img(n, vector<int>(n));
                for(int i=0;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        if(hs+i>=n or hs+i<0)
                            continue;
                        if(vs+j>=n or vs+j<0)
                            continue;
                        img[i+hs][j+vs] = img1[i][j];
                    }
                }
                int cnt = 0;
                for(auto x:v)
                {
                    if(img[x.first][x.second])
                        cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};