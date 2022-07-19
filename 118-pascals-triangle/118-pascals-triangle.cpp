class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
    for (int i = 0; i < numRows; i++)
    {
        vector<int> result;
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                result.push_back(1);
            }
            else
            {
                int s = v[i - 1][j - 1] + v[i - 1][j];
                result.push_back(s);
            }
        }
        v.push_back(result);
    }
    return v;
    }
};