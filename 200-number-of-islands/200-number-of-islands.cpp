class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' and !vis[i][j])
                {
                    cnt++;
                    dfs(vis, grid, i, j);
                }
            }
        }
        return cnt;
    }
    
    void dfs(vector<vector<int>>&vis, vector<vector<char>>&grid, int x, int y)
    {
        vis[x][y] = 1;
        vector<int>dirX = {1, -1, 0, 0};
        vector<int>dirY = {0, 0, 1, -1};
        
        for(int i=0;i<4;i++)
        {
            int currX = x + dirX[i];
            int currY = y + dirY[i];
            if(isSafe(currX, currY, vis, grid)==true)
                dfs(vis, grid, currX, currY);
        }
    }
    
    bool isSafe(int x, int y, vector<vector<int>>&vis, vector<vector<char>>&grid)
    {
        if(x<0 or y<0 or x>=grid.size() or y>=grid[0].size() or grid[x][y]=='0' or vis[x][y]==1)
            return false;
        return true;
    }
};