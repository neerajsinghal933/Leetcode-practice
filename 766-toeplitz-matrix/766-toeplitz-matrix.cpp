class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {        
        int m = matrix.size();
        int n = matrix[0].size();
         
        for (int i = 0; i < m-1; i++)
            for (int j = 1; i+j < m && j < n; j++)
                if (matrix[i][0] != matrix[i + j][j])
                    return false;

        for (int j = 1; j < n-1; j++)
            for (int i = 1; i < m && i+j < n; i++)
                if (matrix[0][j] != matrix[i][i + j])
                    return false;
                        
        return true;
    }
};