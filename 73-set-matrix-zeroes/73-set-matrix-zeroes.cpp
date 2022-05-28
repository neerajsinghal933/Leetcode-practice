class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
        map<int, int>m1,m2;
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[0].size();j++)
            {
                if(v[i][j]==0)
                {
                    m1[i]++;m2[j]++;
                }
            }
        }
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[0].size();j++)
            {
                if(m1[i] || m2[j])
                    v[i][j] = 0;
            }
        }
    }
};