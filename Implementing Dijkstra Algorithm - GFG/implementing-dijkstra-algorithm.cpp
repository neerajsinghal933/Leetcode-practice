// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int src)
    {
        // Code here
        vector<int>dist(v, INT_MAX);
        vector<bool>vis(v, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        
        // vis[src] = 1;
        dist[src] = 0;
        pq.push({0, src});
        while(!pq.empty())
        {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if(vis[u]==true)
                continue;
            vis[u] = true;
            
            for(auto x:adj[u])
            {
                int v = x[0];
                int dist_uv = x[1];
                if(dist[v] == INT_MAX or dist[v] >= d + dist_uv)
                {
                    dist[v] = dist[u] + dist_uv;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends