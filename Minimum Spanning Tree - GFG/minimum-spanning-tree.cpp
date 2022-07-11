// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<bool>vis(v, false);
        vector<int>dist(v, INT_MAX);
        int cnt = 0;
        int src = 0;
        while(1)
        {
            vis[src] = 1;
            for(auto x:adj[src])
            {
                if(vis[x[0]])
                    continue;
                dist[x[0]] = min(dist[x[0]], x[1]);
            }
            src = min_element(dist.begin(), dist.end()) - dist.begin();
            if(dist[src]==INT_MAX)
                return cnt;
            cnt += dist[src];
            dist[src] = INT_MAX;
        }
        // code here
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends