class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        int n = v.size();
        int i=0, j=n-1;
        while(i<j)
        {
            if(v[i] + v[j] == t)
                return {i+1, j+1};
            if(v[i] + v[j] < t)
                i++;
            else
                j--;
        }
        return {};
    }
};