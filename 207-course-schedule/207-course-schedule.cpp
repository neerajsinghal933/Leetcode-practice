class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int>in(n, 0);
        int sz = p.size();
        vector<vector<int>>vis(n, vector<int>());
        queue<int>q;
        
        for(int i=0;i<sz;i++)
        {
            int a = p[i][0];
            int b = p[i][1];
            vis[b].push_back(a);
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
            int temp = q.front();
            q.pop();
            c++;
            for(int x:vis[temp])
            {
                in[x]--;
                if(in[x]==0)
                    q.push(x);
            }
        }
        if(c==n)
            return true;
        return false;
    }
};