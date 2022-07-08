class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>>q;
        int oldColor = image[sr][sc];
        q.push({sr, sc});
        int n = image.size();
        int m = image[0].size();
        image[sr][sc] = color;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        vis[sr][sc] = 1;
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            vis[x][y] = 1;
            for(int i=0;i<4;i++)
            {
                int curr_x = x + dir[i][0];
                int curr_y = y + dir[i][1];
                if(curr_x>=0 and curr_y>=0 and curr_x<n and curr_y<m and image[curr_x][curr_y] == oldColor and vis[curr_x][curr_y]==0)
                {
                    image[curr_x][curr_y] = color;
                    q.push({curr_x, curr_y});
                }
            }
        }
        return image;
    }
};