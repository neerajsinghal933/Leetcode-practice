class Solution {
public:
    
    void dfs(int node, vector<int>*adj, vector<int>&vis, vector<int>&order, int &m, int &cnt, map<int, int>&seen)
    {
        vis[node] = 1;
        order[node] = 1;
        for(int x:adj[node])
        {
            if(!vis[x])
            {
                cnt++;
                seen[x] = cnt;
                dfs(x, adj, vis, order, m, cnt, seen);
            }
            else if(order[x])
            {
                m = cnt - seen[x]+1;
                return;
            }
        }
        order[node] = 0;
        return;
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int>adj[n+1];
        for(int i=0;i<n;i++)
        {
            if(edges[i]!=-1)
                adj[i].push_back(edges[i]);
        }
        int mx = -1;
        vector<int>vis(n+1, 0);
        vector<int>order(n+1, 0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                map<int, int>seen;
                int m = 0, cnt = 0;
                seen[i] = 0;
                dfs(i, adj, vis, order, m, cnt, seen);
                if(m)
                {
                    mx = max(mx, m);
                }
            }
        }
        return mx;
    }
};