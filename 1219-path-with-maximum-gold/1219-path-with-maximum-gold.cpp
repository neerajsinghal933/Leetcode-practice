class Solution {
public:
    int ans =  INT_MIN;
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>vis(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=0)
                    fun(grid, n, m, i, j, vis, grid[i][j]);
            }
        }
        return ans==INT_MIN?0:ans;
    }
    
    void fun(vector<vector<int>>&grid, int n, int m, int i, int j, vector<vector<int>> &vis, int cnt)
    {
        
        if(i<0 or i>=n or j<0 or j>=m or (grid[i][j] == 0) or vis[i][j])
        {
            cnt -= grid[i][j];
            ans = max(ans, cnt);
            return;
        }
        
        vis[i][j] = 1;
        if(i+1<n)
            fun(grid, n, m, i+1, j, vis, cnt + grid[i+1][j]);
        if(i-1>=0)
            fun(grid, n, m, i-1, j, vis, cnt + grid[i-1][j]);
        if(j+1<m)
            fun(grid, n, m, i, j+1, vis, cnt + grid[i][j+1]);
        if(j-1>=0)
            fun(grid, n, m, i, j-1, vis, cnt + grid[i][j-1]);
        ans = max(ans, cnt);
        vis[i][j] = 0;
    }
};