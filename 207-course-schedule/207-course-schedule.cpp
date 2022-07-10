class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int>in(n, 0);
        int sz = p.size();
        vector<vector<int>>adj(n, vector<int>());
        queue<int>q;
        for(int i=0;i<sz;i++)
        {
            int a = p[i][0];
            int b = p[i][1];
            adj[b].push_back(a);
            in[a]++;
        }
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
                q.push(i);
        }
        int c = 0;
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            c++;
            for(int x:adj[t])
            {
                in[x]--;
                if(in[x]==0)
                    q.push(x);
            }
        }
        return c==n;
    }
    
};