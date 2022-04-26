class Solution {
    typedef tuple<int, int, int> Edge;
    
    struct SortEdge {
        bool operator () (Edge const &e1, Edge const & e2) const {
            return get<2>(e1) > get<2>(e2);
        }
    };
    
    typedef priority_queue<Edge, vector<Edge>, SortEdge> Queue;
    
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        Queue pq;
        vector<bool> vis(points.size(), false);
        int num_vis = 0;
        int ans = 0;
        
        // initialize the priority queue with all edges from the first point.
        fill_queue(pq, 0, points, vis);
        vis[0] = true;
        while (num_vis < points.size() && !pq.empty()) {
            // get the shortest edge.
            auto [from, to, dist] = pq.top();           
            pq.pop();
   
            if (!vis[to]) {
                // if the edge is not stale, add it to the MST.
                vis[to] = true;
                num_vis++;
                ans += dist;
                // add new edges from the destination edge to the queue.
                fill_queue(pq, to, points, vis);
            }
        }
        
        return ans;
    }
    
    void fill_queue(Queue &pq, int const point, vector<vector<int>> const &points, vector<bool> const &vis) {
        for (int i=0; i<points.size(); i++) {
            if (i != point && !vis[i]) {
                int dist = abs(points[i][0]-points[point][0]) + abs(points[i][1]-points[point][1]);
                pq.emplace(point, i, dist);
            }
        }
    } 
};