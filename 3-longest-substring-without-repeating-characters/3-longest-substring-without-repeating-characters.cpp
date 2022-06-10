class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int n = s.size();
        int i=0, j=0;
        map<char, int>m;
        while(j<n)
        {
            while(m[s[j]]>0)
            {
                m[s[i++]]--;
            }
            m[s[j]]++;
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};