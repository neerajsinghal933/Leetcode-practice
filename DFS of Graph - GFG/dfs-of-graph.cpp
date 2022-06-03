// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<int>res;
        vector<int>vis(v, 0);
        fun(adj, vis, res, 0, v);
        return res;
    }
    
    void fun(vector<int>adj[], vector<int>&vis, vector<int>&res, int src, int v)
    {
        if(vis[src]==1)
            return;
        vis[src] = 1;
        res.push_back(src);
        for(int i=0;i<adj[src].size();i++)
        {
            if(!vis[adj[src][i]])
            {
                // vis[adj[src][i]]=1;
                fun(adj, vis, res, adj[src][i], v);
            }
        }
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends