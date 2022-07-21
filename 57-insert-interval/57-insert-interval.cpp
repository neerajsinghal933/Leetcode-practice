class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& newInterval) {
        v.push_back(newInterval);
        int n = v.size();
        sort(v.begin(), v.end());
        vector<vector<int>>res;
        int a = v[0][0];
        int b = v[0][1];
        for(int i=1;i<n;i++)
        {
            if(v[i][0]<=b)
                b = max(b, v[i][1]);
            else
            {
                res.push_back({a, b});
                a = v[i][0];
                b = v[i][1];
            }
        }
        res.push_back({a, b});
        return res;
    }
};