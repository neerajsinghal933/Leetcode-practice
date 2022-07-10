// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& p) {
	    // Code here
	    vector<vector<int>>adj(n);
	    vector<int>in(n, 0);
	    for(int i=0;i<p.size();i++)
	    {
	        int a = p[i].first;
	        int b = p[i].second;
	        adj[b].push_back(a);
	        in[a]++;
	    }
	    queue<int>q;
	    for(int i=0;i<n;i++)
	    {
	        if(in[i]==0)
	            q.push(i);
	    }
	    int c =0;
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