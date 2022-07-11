// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int>dist(n, INT_MAX);
	    int src = 0;
	    dist[src] = 0;
	    for(int i=1;i<=n;i++)
	    {
	        bool flag = false;
	        for(auto x:edges)
	        {
	            int u = x[0];
	            int v = x[1];
	            int d = x[2];
	            if(dist[u]!=INT_MAX and dist[u] + d < dist[v])
	            {
	                flag = true;
	                dist[v] = dist[u] + d;
	            }
	        }
	        if(!flag)
	            return false;
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends