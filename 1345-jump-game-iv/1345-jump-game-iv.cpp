class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>>m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        vector<int>dist(n, INT_MAX);
        dist[0] = 0;
        while(!q.empty())
        {
            int idx = q.front();
            // q.front();
            q.pop();
            if(idx==n-1)
                return dist[idx];
            vector<int>&t = m[arr[idx]];
            t.push_back(idx-1);
            t.push_back(idx+1);
            for(int x:t)
            {
                if(x>=0 and x<n and dist[x]>dist[idx]+1)
                {
                    dist[x] = dist[idx] + 1;
                    q.push(x);
                }
            }
            t.clear();
        }
        return -1;
    }
};