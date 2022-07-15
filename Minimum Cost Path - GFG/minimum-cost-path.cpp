// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	int n, m;
	
	bool isSafe(int x, int y)
	{
	    if(x<0 or y<0 or x>=n or y>=n)
	        return false;
	       return true;
	}
	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];
        
        vector<vector<int>>dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!pq.empty())
        {
            pair<int, pair<int, int>> x = pq.top();
            int i = x.second.first;
            int j = x.second.second;
            int d = x.first;
            pq.pop();
            vis[i][j] = 1;
            for(int t=0;t<4;t++)
            {
                int cx = i + dir[t][0];
                int cy = j + dir[t][1];
                if(isSafe(cx, cy) and !vis[cx][cy])
                {
                    if(dist[i][j] + grid[cx][cy] < dist[cx][cy])
                    {
                        dist[cx][cy] = dist[i][j] + grid[cx][cy];
                        pq.push({dist[cx][cy], {cx, cy}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends