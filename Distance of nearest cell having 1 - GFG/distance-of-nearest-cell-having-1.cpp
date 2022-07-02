// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>>dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool check(int x, int y, int n, int m)
    {
        if(x<0 or x>=n or y<0 or y>=m)
            return false;
        return true;
    }
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
	    
	    queue<pair<int, int>>q;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({i, j});
	                dist[i][j] = 0;
	            }
	        }
	    }
	    while(!q.empty())
	    {
	        int x = q.front().first;
	        int y = q.front().second;
	        q.pop();
	        for(int i=0;i<4;i++)
	        {
	            int curr_x = x + dir[i][0];
	            int curr_y = y + dir[i][1];
	            if(check(curr_x, curr_y, n, m)==true)
	            {
	                if(1 + dist[x][y] < dist[curr_x][curr_y])
	                {
	                    dist[curr_x][curr_y] = 1 + dist[x][y];
	                    q.push({curr_x, curr_y});
	                }
	            }
	        }
	        
	    }
	    return dist;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends