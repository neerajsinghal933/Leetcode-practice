class Solution {
public:
    int res =0 ;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>adj[n];
        for(int i=0;i<manager.size();i++)
        {
            int x = manager[i];
            if(x==-1)
                continue;
            adj[x].push_back(i);
        }
        int time = 0;
        
        queue<pair<int, int>>q;
        q.push({headID, 0});
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            if(adj[p.first].size()==0)
            {
                time = max(time, p.second);
                continue;
            }
            for(int i=0;i<adj[p.first].size();i++)
            {
                q.push({adj[p.first][i], p.second + informTime[p.first]});
            }
        }
        return time;
        
        // dfs(adj, informTime, time, headID);
        // return res;
    }
    
    // void dfs(vector<int>adj[], vector<int>&informTime, int time, int node)
    // {
    //     if(adj[node].size()==0)
    //     {
    //         res = max(res, time);
    //         return;
    //     }
    //     time += informTime[node];
    //     for(int x:adj[node])
    //     {
    //         dfs(adj, informTime, time, x);
    //     }
    // }
};