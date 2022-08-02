class Solution {
public:
    int res = -1;
    
    void dfs(vector<int>&edges, vector<int>&vis, int src, int cnt, vector<int>&order)
    {
        if(!vis[src])
        {
            vis[src] = 1;
            order[src] = cnt;
            if(edges[src]!=-1)
            {
                dfs(edges, vis, edges[src], cnt+1, order);
            }
            order[src] = -1;
        }
        else
        {
            if(order[src]!=-1)
            {
                res = max(res, cnt - order[src]);
            }
        }
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        // vector<vector<int>>adj(n);
        // for(int i=0;i<edges.size();i++)
        // {
        //     if(edges[i]!=-1)
        //     adj[i].push_back(edges[i]);
        // }
        vector<int>vis(n, 0);
        vector<int>order(n, -1);
        for(int i=0;i<n;i++)
        {
            // int cnt = 1;
            if(!vis[i])
                dfs(edges, vis, i, 0, order);
        }
        return res;
    }
    
};