class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n, vector<int>(n, -1));
        // vector<vector<int>>adj(n, vector<int>(n, 0));
        
        for(auto x:edges)
        {
            dist[x[0]][x[1]] = x[2];
            dist[x[1]][x[0]] = x[2];
            // adj[x[0]][x[1]] = 1;
            // adj[x[1]][x[0]] = 1;
        }
        
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dist[j][j] = 0;
                    if(i==k or j==k)
                        continue;
                    if(dist[i][k]!=-1 and dist[k][j]!=-1)
                    {
                        if(dist[i][j]==-1)
                            dist[i][j] = dist[i][k] + dist[k][j];
                        else
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        int ans = 0, res = INT_MAX;
        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            for(int j=0;j<n;j++)
            {
                if(dist[i][j]!=-1 and dist[i][j]<=distanceThreshold)
                    cnt++;
            }
            if(cnt<=res)
            {
                res= cnt;
                ans = i;
            }
        }
        return ans;
    }
};