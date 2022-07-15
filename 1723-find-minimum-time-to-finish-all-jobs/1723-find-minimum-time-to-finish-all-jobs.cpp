class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int>t(k, 0);
        sort(jobs.begin(), jobs.end(), greater<int>());
        int ans = INT_MAX;
        int curr = INT_MIN;
        fun(jobs, k, t, ans, curr, 0);
        return ans;
    }
    
    void fun(vector<int>&jobs, int k, vector<int>&t, int &ans, int curr, int idx)
    {
        if(idx>=jobs.size())
        {
            ans = min(ans, curr);
            return;
        }
        if(curr>=ans)
            return;
        for(int i=0;i<k;i++)
        {
            if(i>0 and t[i]==t[i-1])
                continue;
            t[i] += jobs[idx];
            int temp = curr;
            curr = max(curr, t[i]);
            fun(jobs, k, t, ans, curr, idx+1);
            curr = temp;
            t[i] -= jobs[idx];
        }
    }
};