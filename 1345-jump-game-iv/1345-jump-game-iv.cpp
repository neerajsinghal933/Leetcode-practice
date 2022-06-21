class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>>m;
        for(int i=0;i<arr.size();i++)
            m[arr[i]].push_back(i);
        int n  =  arr.size();
        queue<int>q;
        q.push(0);
        vector<int>dist(n, 1e9);
        dist[0] = 0;
        while(!q.empty())
        {
            int idx = q.front();
            q.pop();
            if(idx==n-1)
                return dist[idx];
            vector<int>&v = m[arr[idx]];
            v.push_back(idx-1);
            v.push_back(idx+1);
            
            for(int x:v)
            {
                if(x>=0 and x<n and dist[x]>dist[idx]+1)
                {
                    dist[x] = dist[idx]+1;
                    q.push(x);
                }
            }
            v.clear();
        }
        return -1;
    }
};