class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int, int>m;
        int cnt = 0;
        for(int x:time)
        {
            x %= 60;
            // if(m[60-x])
                cnt+=m[(60-x)%60];
            m[x] += 1;
        }
        return cnt;
    }
};