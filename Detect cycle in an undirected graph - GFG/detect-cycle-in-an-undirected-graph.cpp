// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<int>vis(v, 0);
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                if(dfs(adj, vis, -1, i))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<int>adj[], vector<int>&vis, int par, int src)
    {
        vis[src] =1;
        for(int x:adj[src])
        {
            if(!vis[x])
            {
                if(dfs(adj, vis, src, x))
                    return true;
            }
            else if(par!=x)
                return true;
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