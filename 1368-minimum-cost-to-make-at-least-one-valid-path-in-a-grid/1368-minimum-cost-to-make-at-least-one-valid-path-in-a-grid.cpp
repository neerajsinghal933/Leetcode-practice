class Solution {
public:
    vector<vector<int>>dir = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>>q;
        q.push({0, 0});
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                int r = q.front().first;
                int c = q.front().second;
                // int cost = q.front()[2];
                q.pop();
                // cout<<r<<" "<<c<<endl;
                // if(r==n-1 and c==m-1)
                // {
                //     ans = min(ans, cost);
                //     continue;
                // }
                // if(grid[r][c]==-1)
                //     continue;
                
                for(int k=1;k<=4;k++)
                {
                    int cr = r + dir[k][0];
                    int cc = c + dir[k][1];
                    if(cr<0 or cc<0 or cr>=n or cc>=m )
                        continue;
                    if(grid[r][c]==k)
                    {
                        if(dist[cr][cc]>dist[r][c])
                        {
                            q.push({cr, cc});
                            dist[cr][cc] = dist[r][c];
                        }
                    }
                    else
                    {
                        if(dist[cr][cc]>dist[r][c]+1)
                        {
                            q.push({cr, cc});
                            dist[cr][cc] = dist[r][c]+1;
                        }
                    }
                }
                // grid[r][c] = -1;
            }
        }
        return dist[n-1][m-1];
    }
};