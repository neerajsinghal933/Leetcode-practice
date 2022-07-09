class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int cnt =0;
        int n = adj.size();
        vector<int>vis(n, 0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(adj[i][j] and !vis[i])
                {
                    cnt++;
                    dfs(adj, vis, i);
                }
            }
        }
        return cnt;
    }
    
    void dfs(vector<vector<int>>&adj, vector<int>&vis, int src)
    {
        vis[src] = 1;
        for(int j=0;j<adj[src].size();j++)
        {
            if(adj[src][j] and !vis[j])
                dfs(adj, vis, j);
        }
    }
};