// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isCycle(int src, vector<int>&order, vector<int>adj[], vector<int>&vis)
    {
        vis[src]=1;
        order[src]=1;
        for(auto it:adj[src])
        {
            if(!vis[it])
            {
                if(isCycle(it, order, adj, vis)==true)
                    return true;
            }
            else if(order[it]==1)
                return true;
        }
        order[src]=0;
        return false;
    }

	bool isPossible(int n, vector<pair<int, int> >& v) {
	    // Code here
	    vector<int>adj[n];
	    for(auto it:v)
	    {
	        adj[it.second].push_back(it.first);
	    }
	    vector<int>vis(n, 0);
	    vector<int>order(n, 0);
	    for(int i=0;i<n;i++)
	    {
	        if(!vis[i])
	        {
	            if(isCycle(i, order, adj, vis))
	                return false;
	        }
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends