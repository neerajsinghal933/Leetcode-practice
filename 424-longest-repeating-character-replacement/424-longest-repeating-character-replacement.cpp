class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i=0, j=0;
        int ans = 0, cnt = 0;
        map<char, int>m;
        while(i<n)
        {
            m[s[i]]++;
            cnt = max(cnt, m[s[i]]);
            if(i-j+1 - cnt > k)
            {
                m[s[j]]--;
                j++;
            }
            else
                ans = max(ans, i-j+1);
            i++;
        }
        return ans;
    }
};