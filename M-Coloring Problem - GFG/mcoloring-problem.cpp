// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.


bool isSafe(bool graph[101][101], int n, int x, int idx, vector<int>&col)
{
    for(int i=0;i<n;i++)
    {
        if(graph[idx][i] and col[i]==x)
            return false;
    }
    return true;
}

bool fun(bool graph[101][101], int m, int n, vector<int>&col, int idx)
{
    if(idx==n)
        return true;
    for(int i=1;i<=m;i++)
    {
        if(isSafe(graph, n, i, idx, col)==true)
        {
            col[idx] = i;
            if(fun(graph, m, n, col, idx+1)==true)
                return true;
            col[idx] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    vector<int>col(n, 0);
    return fun(graph, m, n, col, 0);
}



// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends