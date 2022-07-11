class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        queue<pair<int, int>>q;
	    vector<int>col(n, -1);
	    
	    for(int i=0;i<n;i++)
	    {
	        if(col[i]==-1)
	        {
	            q.push({i, 0});
	            col[i] = 0;
	            
	            while(!q.empty())
	            {
	                
	                int v = q.front().first;
	                int c = q.front().second;
	                
	                
	                q.pop();
	                
	                for(auto x:adj[v])
	                {
	                    if(col[x]==c)
	                        return false;
	                        
	                    if(col[x]==-1)
	                    {
	                        col[x] = !c;// ? 0:1;
	                        q.push({x, col[x]});
	                    }
	                }
	            }
	        }
	    }
	    return true;
    }
};