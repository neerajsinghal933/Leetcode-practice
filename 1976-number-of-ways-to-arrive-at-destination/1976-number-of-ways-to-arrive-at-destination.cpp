class Solution {
public:
    typedef long long ll;
    int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll, ll>>>graph(n);
        for(auto x:roads)
        {
            int u = x[0], v = x[1], time = x[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }
        return fun(graph, n, 0);
    }
    
    int fun(vector<vector<pair<ll, ll>>>&graph, int n, int src)
    {
        vector<ll>dist(n, LONG_MAX);
        vector<ll>ways(n);
        ways[src] = 1;
        dist[src] = 0;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
        pq.push({0, 0});    //dist, src
        while(!pq.empty())
        {
            ll d = pq.top().first;
            ll u = pq.top().second;
            pq.pop();
            if(d > dist[u])
                continue;
            for(auto x:graph[u])
            {
                ll v = x.first;
                ll time = x.second;
                if(dist[v] > d + time)
                {
                    dist[v] = d + time;
                    ways[v] = ways[u];
                    pq.push({dist[v], v});
                }
                else if(dist[v] == d + time)
                {
                    ways[v] = (ways[v] + ways[u])%mod;
                }
            }
        }
        return ways[n-1];
    }
};