class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>board(n);
        string s(n, '.');
        for(int i=0;i<n;i++)
        {
            board[i] = s;
        }
        solve(board, n, 0, res);
        return res;
    }
    
    void solve(vector<string>&board, int n, int col, vector<vector<string>>&res)
    {
        if(col==n)
        {
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(board, row, col)==true)
            {
                board[row][col] = 'Q';
                solve(board, n, col+1, res);
                board[row][col] = '.';
            }
        }
    }
    
    bool isSafe(vector<string>&board, int x, int y)
    {
        int n = board.size();
        int m = board[0].size();
        for(int j=0;j<y;j++)
        {
            if(board[x][j]=='Q')
                return false;
        }
        for(int i=x, j=y; i>=0 and j>=0; i--, j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
        for(int i=x, j=y; i<n and j>=0; i++, j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
        return true;
    }
    
};