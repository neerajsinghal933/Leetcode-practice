// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int minSteps(int m, int n, int d)
	{
	    // Code here
	    if(d>m and d>n)
	        return -1;
	    queue<pair<int, int>>q;
	    if(d==0)
	        return 0;
	   int step = 0;
	   vector<vector<int>>vis(m+1, vector<int>(n+1, 0));
	   q.push({0, 0});
	   while(!q.empty())
	   {
	       int sz = q.size();
	       while(sz--)
	       {
	           int x = q.front().first;
	           int y = q.front().second;
	           q.pop();
	           if(x==d or y==d)
	            return step;
	           if(vis[x][y])
	            continue;
	           vis[x][y] = 1;
	           if(!vis[x][n])
	            q.push({x, n});
	           if(!vis[m][y])
	            q.push({m, y});
	            int a = min(x, n-y);
	            if(!vis[x-a][y+a])
	                q.push({x-a, y+a});
	           int b = min(m-x, y);
	           if(!vis[x+b][y-b])
	            q.push({x+b, y-b});
	            if(!vis[x][0])
	            q.push({x, 0});
	            if(!vis[0][y])
	            q.push({0, y});
	       }
	       step++;
	   }
	   return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, d;
		cin >> m >> n >> d;
		Solution ob;
		int ans = ob.minSteps(m, n, d);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends