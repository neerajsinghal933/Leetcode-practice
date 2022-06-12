class Solution {
public:
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>>vis(n+1, vector<int>(m+1, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans = max(ans, fun(matrix, i, j, vis));
            }
        }
        return ans;
    }
    
    int fun(vector<vector<int>>&matrix, int i, int j, vector<vector<int>>&vis)
    {
        if(vis[i][j]!=0)
            return vis[i][j];
        int max_ans = 0;
        for(int p=0;p<4;p++)
        {
            int curr_x = i + dir[p][0];
            int curr_y = j + dir[p][1];
            
            if(isValid(curr_x, curr_y, matrix) and matrix[curr_x][curr_y] > matrix[i][j])
                max_ans = max(max_ans, fun(matrix, curr_x, curr_y, vis));
        }
        return vis[i][j] = 1 + max_ans;
    }
    
    bool isValid(int x, int y, vector<vector<int>>&v)
    {
        int n = v.size();
        int m = v[0].size();
        if(x<0 or x>=n or y<0 or y>=m)
            return false;
        return true;
    }
};