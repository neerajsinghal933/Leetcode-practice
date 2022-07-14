// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(vector<int>adj[], int src, vector<int>&vis)
    {
        vis[src] = true;
        for(int x:adj[src])
        {
            if(!vis[x])
                dfs(adj, x, vis);
        }
    }
    
	int findMotherVertex(int v, vector<int>adj[])
	{
	    // Code here
	    for(int i=0;i<v;i++)
	    {
	        vector<int>vis(v, 0);
	        dfs(adj, i, vis);
	        bool flag = false;
	        for(int j=0;j<v;j++)
	        {
	            if(vis[j]==0)
	            {
	                flag = true;
	                break;
	            }
	        }
	        if(!flag)
	            return i;
	    }
	    return -1;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends