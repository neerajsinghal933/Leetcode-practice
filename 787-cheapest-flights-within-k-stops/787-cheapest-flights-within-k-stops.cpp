class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>>adj[n];
        for(auto x:flights)
        {
            adj[x[0]].push_back({x[1], x[2]});
        }
        int steps = 0, res = INT_MAX;
        queue<pair<int, int>>q; //dest, cost
        
        q.push({src, 0});
        vector<int>vis(n, 0);
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                int u = q.front().first;
                int cost = q.front().second;
                q.pop();
                
                if(u==dst)
                {
                    res = min(res, cost);
                }
                
                for(auto x:adj[u])
                {
                    if(cost + x.second <= res and (vis[x.first]==0 or cost + x.second < vis[x.first]))
                    {
                        vis[x.first] = cost + x.second;
                        q.push({x.first,cost+ x.second});
                    }
                }
            }
            if(steps++ >k)
                break;
        }
        return res==INT_MAX?-1:res;
    }
};