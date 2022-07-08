// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0 or m[n-1][n-1]==0)
            return {"-1"};
        vector<string>res;
        vector<vector<int>>vis(n, vector<int>(n, 0));
        fun(m, n, vis, res, 0, 0, "");
        return res;
    }
    
    void fun(vector<vector<int>>&m, int n, vector<vector<int>>&vis, vector<string>&res, int x, int y, string temp)
    {
        if(x==n-1 and y==n-1)
        {
            res.push_back(temp);
            return ;
        }
        if(x<0 or y<0 or x>=n or y>=n or vis[x][y] or m[x][y]==0)
            return;
        vis[x][y] = true;
        fun(m, n, vis, res, x+1, y, temp + "D");
        fun(m, n, vis, res, x, y-1, temp + "L");
        fun(m, n, vis, res, x, y+1, temp + "R");
        fun(m, n, vis, res, x-1, y, temp + "U");
        vis[x][y] = false;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends