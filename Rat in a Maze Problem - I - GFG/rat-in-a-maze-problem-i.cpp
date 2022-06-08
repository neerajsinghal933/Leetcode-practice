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
        vector<string>res;
        vector<vector<int>>vis(n, vector<int>(n, 0));
        if(m[0][0] ==0 or m[n-1][n-1]==0)
            return {};
        fun(m, n, res, "", 0, 0, vis);
        return res;
    }
    
    void fun(vector<vector<int>>&m, int n, vector<string>&res, string t, int x, int y, vector<vector<int>>&vis)
    {
        if(x<0 or y<0 or x>=n or y>=n or vis[x][y]==1)
            return;
        if(x==n-1 and y==n-1)
        {
            res.push_back(t);
            return;
        }
        vis[x][y]=1;
        if(m[x][y])
        {
            vis[x][y] = 1;
            fun(m, n, res, t + 'D', x+1, y, vis);
            fun(m, n, res, t + 'L', x, y-1, vis);
            fun(m, n, res, t + 'R', x, y+1, vis);
            fun(m, n, res, t + 'U', x-1, y, vis);
            
        }
        vis[x][y] = 0;
        
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