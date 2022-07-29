class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>in(n, 0);
        for(auto x:edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
            in[x[0]]++;
            in[x[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(in[i]==1){
                in[i]--;
                q.push(i);
            }
        }
        if(n==1)
            return {0};
        vector<int>ans;
        while(!q.empty())
        {
           
            ans.clear();
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                 int d = q.front();
                q.pop();
                for(int x:adj[d])
                {
                    in[x]--;
                    if(in[x]==1)
                        q.push(x);
                }
                ans.push_back(d);
            }
            
        }
        return ans;
    }
};