class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int>vis(401, 0);
        queue<int>q;
        q.push(1);
        vis[1] = 1;
        int cnt =0 ;
        while(!q.empty())
        {
            cnt++;
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                int t = q.front();
                q.pop();
                for(int k=1;k<=6;k++)
                {
                    int d = t + k;
                    if(d>n*n)
                        break;
                    if(vis[d]==1)
                        continue;
                    vis[d] = 1;
                    d = fun(board, n, d);
                    if(d==n*n)
                        return cnt;
                    q.push(d);
                }
            }
        }
        return -1;
    }
    
    int fun(vector<vector<int>>&board, int n, int d)
    {
        int r, c, k;
        r  = (n-1) - (d-1)/n;
        c = (d-1)%n;
        if(r%2==n%2)
            c = n-1-c;
        if(board[r][c]==-1)
            return d;
        return board[r][c];
    }
};