class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& v, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        int i=0;
        for(auto x:v)
        {
            pq.push({x[0]*x[0] + x[1] * x[1], i});
            i++;
        }
        vector<vector<int>>res;
        while(k--)
        {
            pair<int, int>a = pq.top();
            pq.pop();
            res.push_back({v[a.second][0], v[a.second][1]});
        }
        return res;
    }
};