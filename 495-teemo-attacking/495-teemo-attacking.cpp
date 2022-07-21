class Solution {
public:
    int findPoisonedDuration(vector<int>& v, int time) {
        int cnt = 0;
        int n = v.size();
        int a = v[0];
        int curr = a + time - 1;
        for(int i=1;i<n;i++)
        {
            if(v[i]<=curr)
                curr = v[i] + time - 1;
            else
            {
                cnt += curr - a + 1;
                a = v[i];
                curr = v[i] + time - 1;
            }
        }
        cnt += curr - a + 1;
        return cnt;
    }
};