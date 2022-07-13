// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    int find_set(int x, vector<int>&par)
    {
        if(par[x]==-1)
            return x;
        return par[x] = find_set(par[x], par);
    }
    
    int union_set(int x, int y, vector<int>&par)
    {
        par[x] = y;
        // par[y] = x;
        // int s1 = find_set(x, par);
        // int s2 = find_set(y, par);
        // if(s1!=s2)
        // {
        //     par[s1] = s2;
        //     // par[s2] = s1;
        // }
    }
    
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<int>par(v, -1);
        for(int i=0;i<v;i++)
        {
            for(int x:adj[i])
            {
                if(x>i)
                {
                int s1 = find_set(i, par);
                int s2 = find_set(x, par);
                if(s1!=s2)
                    union_set(s1, s2, par);
                else
                    return true;
                }
            }
        }
        return false;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends