// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	static bool comp(vector<int>&a, vector<int>&b)
	{
	    return a[2]<b[2];
	}
	
	int find_set(int x, vector<int>&par)
    {
        if(par[x]==-1)
            return x;
        return par[x] = find_set(par[x], par);
    }
    
    int union_set(int x, int y, vector<int>&par, vector<int>&rank)
    {
        if(rank[x]<rank[y])
        {
            par[x] = y;
            rank[y] += rank[x];
        }
        else{
            par[y] = x;
            rank[x] += rank[y];
        }
    }
	
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        vector<vector<int>>graph;
        for(int i=0;i<v;i++)
        {
            for(auto x:adj[i])
            {
                graph.push_back({i, x[0], x[1]});
            }
        }
        sort(graph.begin(), graph.end(), comp);
        vector<int>par(v, -1), rank(v, 1);
        int ans = 0;
        for(int i=0;i<graph.size();i++)
        {
            int u = graph[i][0];
            int v = graph[i][1];
            int d = graph[i][2];
            int s1 = find_set(u, par);
            int s2 = find_set(v, par);
            if(s1!=s2)
            {
                ans += d;
                union_set(s1, s2, par, rank);
            }
        }
        return ans;
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