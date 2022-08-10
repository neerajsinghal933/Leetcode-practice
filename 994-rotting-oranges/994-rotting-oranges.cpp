class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                    q.push({i, j});
            }
        }
        int cnt = 0;
        vector<vector<int>>dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty())
        {
            cnt++;
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int cx = x + dir[k][0];
                    int cy = y + dir[k][1];
                    
                    if(cx>=0 and cx<n and cy>=0 and cy<m and grid[cx][cy] == 1)
                    {
                        q.push({cx, cy});
                        grid[cx][cy] = 2;
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        if(cnt==0)
            return 0;
        return cnt-1;
    }
};