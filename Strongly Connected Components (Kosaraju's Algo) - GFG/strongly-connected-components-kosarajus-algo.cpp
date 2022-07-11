// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	stack<int>st;
	
	void dfs(vector<int>adj[], int src, vector<int>&vis)
	{
	    vis[src] = 1;
	    for(int x:adj[src])
	    {
	        if(!vis[x])
	            dfs(adj, x, vis);
	    }
	    st.push(src);
	}
	
    int kosaraju(int v, vector<int> adj[])
    {
        //code here
        vector<int>vis(v, 0);
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                dfs(adj, i, vis);
            }
        }
        vector<int>temp;
        while(!st.empty())
        {
            //cout<<st.top()<<" ";
            temp.push_back(st.top());
            st.pop();
        }
        vis.assign(v, 0);
        vector<int>adj1[v];
        for(int i=0;i<v;i++)
        {
            for(int x:adj[i])
            {
                adj1[x].push_back(i);
            }
        }
        int cnt = 0;
        for(int i=0;i<v;i++)
        {
            int x = temp[i];
            if(!vis[x])
            {
                dfs(adj1, x, vis);
                cnt++;
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends