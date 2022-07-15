class Solution {
public:
    
    int find(int x, vector<int>&par)
    {
        if(par[x]==-1)
            return x;
        return par[x] = find(par[x], par);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>par(n+1, -1);
        for(auto x:edges)
        {
            int a = x[0];
            int b = x[1];
            int s1 = find(a, par);
            int s2 = find(b, par);
            if(s1!=s2)
                par[s1] = s2;
            else
                return {a, b};
        }
        return {};
    }
};