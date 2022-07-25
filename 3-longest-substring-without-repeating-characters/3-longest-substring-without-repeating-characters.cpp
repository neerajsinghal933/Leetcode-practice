class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, cnt = 0;
        int n = s.size();
        int i=0, j=0;
        map<char, int>m;
        while(i<n)
        {
            while(m[s[i]]>0)
            {
                m[s[j]]--;
                j++;
            }
            m[s[i]]++;
            ans = max(ans, i-j+1);
            i++;
        }
        return ans;
    }
};