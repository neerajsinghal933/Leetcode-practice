// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.

bool isSafe(bool graph[101][101], int v, int x, vector<int>&col, int idx)
{
    for(int i=0;i<v;i++)
    {
        if(graph[idx][i]==1 and col[i]==x)
        return false;
    }
    return true;
}

bool fun(bool graph[101][101], int m, int v, vector<int>&col, int idx)
{
    if(idx==v)
    return true;
    
    for(int i=1;i<=m;i++)
    {
        if(isSafe(graph, v, i, col, idx)==true)
        {
            col[idx] = i;
            if(fun(graph, m, v, col, idx+1))
                return true;
            col[idx] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    vector<int>col(V, 0);
    if(fun(graph, m, V, col, 0)==true)
    return true;
    return false;
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