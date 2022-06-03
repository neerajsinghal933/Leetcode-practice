class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& v) {
        int sz = v.size();
        if(n-1 > sz)
            return -1;
        vector<int>adj[n];
        for(int i=0;i<sz;i++)
        {
            int a = v[i][0];
            int b = v[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int cnt = 0;
        vector<int>vis(n, 0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i]){
                cnt++;
                dfs(adj, i, vis);
            }
        }
        return cnt-1;
    }
    
    void dfs(vector<int>adj[], int i, vector<int>&vis)
    {
        vis[i]=1;
        for(auto it:adj[i])
        {
            if(!vis[it])
                dfs(adj, it, vis);
        }
    }
};