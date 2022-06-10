class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool>vis(n, 0);
        vector<int>dist(n, INT_MAX);
        int ans = 0;
        dist[0] = 0;
        int curr = 0;
        while(1)
        {
            vis[curr] = true;
            for(int i=0;i<n;i++)
            {
                if(vis[i]==true)
                    continue;
                dist[i] = min(dist[i], abs(points[i][0]-points[curr][0]) + abs(points[i][1] - points[curr][1]));
            }
            curr = min_element(dist.begin(), dist.end()) - dist.begin();
            if(dist[curr]==INT_MAX)
                return ans;
            ans += dist[curr];
            dist[curr] = INT_MAX;
            
        }
        return ans;
    }
};