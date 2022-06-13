// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    
    bool fun(vector<vector<int>>&v, int x, int y, int n, int m)
    {
        if(x<0 or x>=n or y<0 or y>=m or v[x][y]!=1)
            return false;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>>q;
        int res = -1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i, j});
                    grid[i][j]=-1;
                }
            }
        }
        while(!q.empty())
        {
            int sz = q.size();
            for(int k=0;k<sz;k++)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(fun(grid, i-1, j, n, m))
                {
                    q.push({i-1, j});
                    grid[i-1][j]=-1;
                }
                if(fun(grid, i+1, j, n, m))
                {
                    q.push({i+1, j});
                    grid[i+1][j]=-1;
                }
                if(fun(grid, i, j-1, n, m))
                {
                    q.push({i, j-1});
                    grid[i][j-1]=-1;
                }
                if(fun(grid, i, j+1, n, m))
                {
                    q.push({i, j+1});
                    grid[i][j+1]=-1;
                }
            }
            res++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return res==-1?-1:res;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends