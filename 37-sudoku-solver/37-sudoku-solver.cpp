class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        fun(board, 0, 0);
    }
    
    bool fun(vector<vector<char>>&board, int i, int j)
    {
        if(i==9 && j==0)
            return true;
        if(i>=9 || j>=9)
            return false;
        if(board[i][j]!='.')
        {
            if(j==8)
            {
                return fun(board, i+1, 0);
            }
            else
            {
                return fun(board, i, j+1);
            }
            // return false;
        }
        for(char c = '1'; c<='9'; c++)
        {
            if(isSafe(board, i, j, c)==true)
            {
                board[i][j] = c;
                // cout<<"K";
                if(j==8){
                    if(fun(board, i+1, 0))
                        return true;
                }
                else{
                    if(fun(board, i, j+1))
                        return true;
                }
                
            }
           board[i][j] = '.';
        }
        return false;
    }
    
    bool isSafe(vector<vector<char>>board, int x, int y, int c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][y]==c)
                return false;
        }
        for(int j=0;j<9;j++)
        {
            if(board[x][j]==c)
                return false;
        }
        x = x-x%3;
        y = y-y%3;
        for(int i=x;i<x+3;i++)
        {
            for(int j=y;j<y+3;j++)
            {
                if(board[i][j]==c)
                    return false;
            }
        }
        return true;
    }
};