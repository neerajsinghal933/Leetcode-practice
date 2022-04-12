class Solution {
public:
    
    int dirX[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dirY[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        fun(board, n, m, 0, 0);
        return;
    }
    
    void fun(vector<vector<int>>&board, int n, int m, int x, int y)
    {
        if(x==n and y==0)
            return;
        int cnt = cntNeighbour(board, n, m, x, y);
        if(y==m-1)
            fun(board, n, m, x+1, 0);
        else
            fun(board, n, m, x, y+1);
        if(board[x][y])
        {
            if(cnt<=1 or cnt>3)
                board[x][y] = 0;
            else
                board[x][y] = 1;
        }
        else
        {
            if(cnt==3)
                board[x][y] = 1;
        }
        return;
    }
    
    int cntNeighbour(vector<vector<int>>&board, int n, int m, int x, int y)
    {
        if(x<0 or y<0 or x>=n or y>=m)
            return 0;
        int cnt = 0;
        for(int i=0;i<8;i++)
        {
            int tempX = x + dirX[i];
            int tempY = y + dirY[i];
            if(tempX<0 or tempX>=n or tempY<0 or tempY>=m)
                continue;
            if(board[tempX][tempY])
            {
                cnt++;
            }
        }
        return cnt;
    }
};