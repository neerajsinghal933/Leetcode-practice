class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int, int>>q;
        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        q.push({sr, sc});
        vector<vector<int>>vis(n, vector<int>(m, 0));
        vis[sr][sc]=1;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            vis[x][y] = 1;
            q.pop();
            if(x-1 >= 0 and image[x-1][y]==oldColor and vis[x-1][y]==0)
            {
                image[x-1][y] = newColor;
                q.push({x-1, y});
            }
            if(x+1 < n and image[x+1][y]==oldColor and vis[x+1][y]==0)
            {
                image[x+1][y] = newColor;
                q.push({x+1, y});
            }
            if(y-1 >= 0 and image[x][y-1]==oldColor and vis[x][y-1]==0)
            {
                image[x][y-1] = newColor;
                q.push({x, y-1});
            }
            if(y+1 < m and image[x][y+1]==oldColor and vis[x][y+1]==0)
            {
                image[x][y+1] = newColor;
                q.push({x, y+1});
            }
        }
        return image;
    }
};