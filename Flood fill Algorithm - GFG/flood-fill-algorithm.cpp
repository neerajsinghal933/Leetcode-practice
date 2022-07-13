// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int n, m;
    
    bool isSafe(int x, int y)
    {
        if(x<0 or x>=n or y<0 or y>=m)
            return false;
        return true;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        n = image.size();
        m = image[0].size();
        vector<vector<int>>dp = image;
        int oldColor = dp[sr][sc];
        if(dp[sr][sc]==newColor)
            return dp;
        queue<pair<int, int>>q;
        q.push({sr, sc});
        vector<vector<int>>vis(n, vector<int>(m, 0));
        dp[sr][sc] = newColor;
        vector<vector<int>>dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            vis[sr][sc] = 1;
            for(int i=0;i<4;i++)
            {
                int cx = x + dir[i][0];
                int cy = y + dir[i][1];
                if(isSafe(cx, cy) and !vis[cx][cy] and dp[cx][cy]==oldColor)
                {
                    q.push({cx, cy});
                    dp[cx][cy] = newColor;
                }
            }
        }
        return dp;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends