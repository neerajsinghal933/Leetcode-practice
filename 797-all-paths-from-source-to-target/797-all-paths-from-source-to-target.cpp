class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>res;
        vector<int>temp;
        int n = graph.size();
        vector<int>vis(n, 0);
        temp.push_back(0);
        fun(graph, temp, res, vis, 0, n-1);
        return res;
    }
    
    void fun(vector<vector<int>>&graph, vector<int>temp, vector<vector<int>>&res, vector<int>&vis, int src, int dest)
    {
        if(src == dest)
        {
            res.push_back(temp);
            return;
        }
        if(vis[src]==1)
            return;
        vis[src] = 1;
        for(auto x:graph[src])
        {
            if(!vis[x])
            {
                temp.push_back(x);
                fun(graph, temp, res, vis, x, dest);
                temp.pop_back();
            }
        }
        vis[src] = 0;
    }
};