// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution {
public:
    bool pathMoreThanK(int v, int e, int k, int *a) 
    { 
       //  Code Here
       vector<pair<int, int>>adj[v];
       for(int i=0;i<3*e;i+=3)
       {
           adj[a[i]].push_back({a[i+1], a[i+2]});
           adj[a[i+1]].push_back({a[i], a[i+2]});
       }
       vector<bool>vis(v, 0);
       return dfs(adj, 0, k, vis);
    } 
    
    bool dfs(vector<pair<int, int>>adj[], int src, int k, vector<bool>&vis)
    {
        vis[src] = 1;
        if(k<=0)
            return true;
        for(auto x:adj[src])
        {
            int v = x.first;
            int d = x.second;
            if(!vis[v])
            {
                if(dfs(adj, v, k-d, vis)==true)
                    return true;
            }
        }
        return vis[src] = false;
    }
};




// { Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends