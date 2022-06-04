class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        // vector<string>temp;
        vector<string>board(n);
        string s(n, '.');
        for(int i=0;i<n;i++)
            board[i] = s;
        
        solve(board, n, 0, res);
        return res;
    }
    
    void solve(vector<string>&board, int n, int col, vector<vector<string>>&res)
    {
        if(col==n)
        {
            // cout<<"Y";
            res.push_back(board);return;
        }
        for(int row=0; row<n; row++)
        {
            if(isSafe(board, row, col)==true)
            {
                
                board[row][col] = 'Q';
                solve(board, n, col+1, res);
                board[row][col] = '.';
            }
        }
    }
    
    bool isSafe(vector<string>&board, int row, int col)
    {
        for(int j=0;j<col;j++)
        {
            if(board[row][j]=='Q')
            return  false;
        }
        for(int i=row, j=col;i>=0 and j>=0; i--, j--)
        {
            if(board[i][j]=='Q')
            return false;
        }
        for(int i=row, j=col; i<board.size() and j>=0; i++,j--)
        {
            if(board[i][j]=='Q')
            return false;
        }
        return true;
    }
};