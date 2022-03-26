// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSafe(int row, int col, vector<vector<int>>&board)
    {
        for(int j=0;j<col;j++)
        {
            if(board[row][j]==1)
            return  false;
        }
        for(int i=row, j=col;i>=0 and j>=0; i--, j--)
        {
            if(board[i][j]==1)
            return false;
        }
        for(int i=row, j=col; i<board.size() and j>=0; i++,j--)
        {
            if(board[i][j]==1)
            return false;
        }
        return true;
    }

    void solve(vector<vector<int>>&board, int n, int col, vector<vector<int>>&res, vector<int>&temp)
    {
        if(col==n)
        {
            res.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(row, col, board)==true)
            {
                board[row][col] = 1;
                temp.push_back(row+1);
                solve(board, n, col+1, res, temp);
                temp.pop_back();
                board[row][col] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>res;
        vector<int>temp;
        vector<vector<int>>board(n, vector<int>(n, 0));
        solve(board, n, 0, res, temp);
        return res;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends