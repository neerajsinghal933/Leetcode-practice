class Solution {
public:
    int n, m;
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0] and fun(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    
    bool fun(vector<vector<char>>&board, string& word, int i, int j, int idx)
    {
        if(idx==word.size())
            return true;
        if(i<0 or j<0 or i>=n or j>=m or board[i][j]!=word[idx])
            return false;
        board[i][j] = '0';
        bool flag = fun(board, word, i+1, j, idx+1) or fun(board, word, i-1, j, idx+1) or fun(board, word, i, j+1, idx+1) or fun(board, word, i, j-1, idx+1);
        board[i][j] = word[idx];
        return flag;
    }
};