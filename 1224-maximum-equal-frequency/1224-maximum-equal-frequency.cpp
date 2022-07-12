class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)
            return n;
        unordered_map<int, int>m;
        int mx_freq = 0, mx_cnt = 0, ans=0;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
            if(m[nums[i]] > mx_freq)
            {
                mx_freq = m[nums[i]];
                mx_cnt = 1;
            }
            else if(m[nums[i]]==mx_freq)
                mx_cnt++;
            
            if(i+1 - (mx_freq * mx_cnt) == 1)
                ans = max(ans, i+1);
            else if(mx_cnt==1 and mx_freq + (m.size()-1) * (mx_freq-1) == i+1)
                ans = max(ans, i+1);
        }
        if(mx_freq==1)
             return n;
        return ans;
    }
};                                                      