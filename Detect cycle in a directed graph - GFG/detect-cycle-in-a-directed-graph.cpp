// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<int>vis(v, 0), order(v, 0);
        for(int i=0;i<v;i++)
        {
            bool c = dfs(v, adj, vis, order, i);
            if(c)
                return true;
        }
        return false;
    }
    
    bool dfs(int v, vector<int>adj[], vector<int>&vis, vector<int>&order, int src)
    {
        vis[src] =  1;
        order[src] = 1;
        for(int x:adj[src])
        {
            if(!vis[x])
            {
                if(dfs(v, adj, vis, order, x)==true)
                    return true;
            }
            if(order[x])
                return true;
        }
        order[src] = 0;
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends