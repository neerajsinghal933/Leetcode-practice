#define pii pair<int, pair<int, int>>
class Solution {
public:
     bool isSafe(int x, int y)
        {
            if(x<0 or y<0 or x>=n or y>=m)
                return false;
            return true;
        }
    int n, m;
    vector<vector<int>>dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int minimumObstacles(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        
        priority_queue<pii, vector<pii>, greater<pii>>pq;
        
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        
        while(!pq.empty())
        {
            int d = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            
            pq.pop();
            
            for(int i=0;i<4;i++)
            {
                int curr_x = x + dir[i][0];
                int curr_y = y + dir[i][1];
                
                if(isSafe(curr_x, curr_y))
                {
                    int curr_d = d;
                    if(grid[x][y]==1)
                        curr_d += 1;
                    if(dist[curr_x][curr_y]>curr_d)
                    {
                        dist[curr_x][curr_y] = curr_d;
                        pq.push({curr_d, {curr_x, curr_y}});
                    }
                }
                
                
            }
            
        }
        return dist[n-1][m-1];
       
    }
};