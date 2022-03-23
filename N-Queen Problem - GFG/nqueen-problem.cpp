// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isSafe(int x, int y, vector<vector<int>>vis, int n)
    {
        for(int i=0;i<y;i++)
        {
            if(vis[x][i]==1)
                return false;
        }
        for(int i=x,j=y;i>=0 and j>=0; i--, j--)
        {
            if(vis[i][j])
                return false;
        }
        for(int i=x, j=y; i<n and j>=0; i++, j--)
        {
            if(vis[i][j])
            return false;
        }
        return true;
    }
    
    void fun(vector<vector<int>>&vis, int n, int col, vector<int>&temp, vector<vector<int>>&res)
    {
        if(col>=n)
        {
            res.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(isSafe(row, col, vis, n)==true)
            {
                vis[row][col] = 1;
                temp.push_back(row+1);
                fun(vis, n, col+1, temp, res);
                temp.pop_back();
                vis[row][col] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>res;
        vector<vector<int>>vis(n, vector<int>(n, 0));
        vector<int>temp;
        fun(vis, n, 0, temp, res);
        sort(res.begin(), res.end());
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