class Solution {
public:
    int n, m;
    
    vector<vector<int>>dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool isSafe(int x, int y)
    {
        if(x<0 or y<0 or x>=n or y>=m)
            return false;
        return true;
    }
    
    void dfs(vector<vector<int>>&grid, vector<vector<int>>&vis, int x, int y)
    {
        vis[x][y] = 1;
        for(int i=0;i<4;i++)
        {
            int cx = x + dir[i][0];
            int cy = y + dir[i][1];
            if(isSafe(cx, cy) and grid[cx][cy] and !vis[cx][cy])
            {
                dfs(grid, vis, cx, cy);
            }
        }
    }
    
    int connected(vector<vector<int>>& grid)
    {
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] and !vis[i][j])
                {
                    cnt++;
                    dfs(grid, vis, i, j);
                }
            }
        }
        return cnt;
    }
    
    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cnt = connected(grid);
        
        if(cnt!=1)
            return 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    grid[i][j] = 0;
                    if(connected(grid)!=1)
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};