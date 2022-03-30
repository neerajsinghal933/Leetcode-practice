class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int n = v.size();
        int m = v[0].size();
        
        if(t < v[0][0] or t > v[n-1][m-1])
            return false;
        int i;
        for(i=0;i<n;i++)
        {
            if(v[i][m-1] >= t)
                break;
        }
        
        for(int j=0;j<m;j++)
        {
            if(v[i][j]==t)
                return true;
        }
        return false;
    }
};