class Solution {
public:
    
    bool dfs(vector<vector<int>>&graph, vector<int>&vis, vector<int>&ans, vector<int>&order, int src)
    {
        vis[src] = 1;
        order[src] = 1;
        for(int x:graph[src])
        {
            if(!vis[x])
            {
                if(dfs(graph, vis, ans, order, x))
                    return ans[src] = true;
            }
            else if(order[x]==1)
                return ans[src] = true;
        }
        order[src] = 0;
        return ans[src] = false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n, 0), ans(n, 0), order(n, 0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
                dfs(graph, vis, ans, order, i);
        }
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            if(ans[i]==0)
                res.push_back(i);
        }
        return res;
    }
    
};
