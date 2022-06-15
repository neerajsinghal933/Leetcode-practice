class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>>adj[n+1];
        int sz = times.size();
        for(int i=0;i<sz;i++)
        {
            adj[times[i][0]].push_back({times[i][2], times[i][1]});
        }
        vector<int>dist(n+1, INT_MAX);
        dist[k] = 0;
        dist[0] = 0;
        vector<bool>vis(n+1, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, k});
        while(!pq.empty())
        {
            int u = pq.top().second;
            int dist_u = pq.top().first;
            pq.pop();
            if(vis[u])
                continue;
            vis[u] = true;
            for(auto x:adj[u])
            {
                int v = x.second;
                int d = x.first;
                if(dist[v] > dist[u] + d)
                {
                    dist[v] = dist[u] + d;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = *max_element(dist.begin(), dist.end());
        return ans==INT_MAX?-1:ans;
    }
};