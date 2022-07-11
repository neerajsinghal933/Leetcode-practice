class Solution {
public:
    bool isSafe(int x, int y, int n, int m)
    {
        if(x<0 or y<0 or x>=n or y>=m)
            return false;
        return true;
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        queue<pair<int, int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 or j==0 or i==n-1 or j==m-1) and board[i][j]=='O')
                {
                    
                    q.push({i, j});
                }
            }
        }
        vector<vector<int>>dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            vis[x][y]=1;
            for(int i=0;i<4;i++)
            {
                int cx = x + dir[i][0];
                int cy = y + dir[i][1];
                if(isSafe(cx, cy, n, m) and board[cx][cy]=='O' and vis[cx][cy]==0)
                {
                    q.push({cx, cy});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j])
                    board[i][j] = 'X';
            }
        }
        return ;
        
    }
};