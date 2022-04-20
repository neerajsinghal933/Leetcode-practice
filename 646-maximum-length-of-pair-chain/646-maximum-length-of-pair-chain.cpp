class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int cnt = 1;
        int last = pairs[0][1];
        
        for(int i=1;i<pairs.size();i++)
        {
            if(pairs[i][0] > last)
            {
                cnt++;
                last = pairs[i][1];
            }
            else
            {
                if(pairs[i][1] < last)
                    last = pairs[i][1];
            }
        }
        return cnt;
    }
};