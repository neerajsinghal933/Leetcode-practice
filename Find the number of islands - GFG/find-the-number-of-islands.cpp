// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    vector<vector<int>>dir = {{1, 0}, {1, 1}, {1, -1}, {-1, 0},{-1, 1}, {-1, -1}, {0, 1}, {0, -1}};
    
    bool isSafe(int x, int y, vector<vector<int>>&vis, vector<vector<char>>&grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(x<0 or x>=n or y<0 or y>=m or grid[x][y]=='0' or vis[x][y])
            return false;
        return true;
    }
    
    void dfs(int x, int y, vector<vector<int>>&vis, vector<vector<char>>&grid)
    {
        vis[x][y] = 1;
        for(int i=0;i<8;i++)
        {
            int cx = x + dir[i][0];
            int cy = y + dir[i][1];
            if(isSafe(cx, cy, vis, grid)==true)
            {
                dfs(cx, cy, vis, grid);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
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
                    dfs(i, j, vis, grid);
                }
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends