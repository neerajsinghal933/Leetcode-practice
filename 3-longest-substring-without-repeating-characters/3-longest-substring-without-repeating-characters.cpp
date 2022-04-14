class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0, j=0;
        map<char, int>m;
        int ans = INT_MIN;
        for(j=0;j<n;j++)
        {
            while(m[s[j]]!=0)
            {
                if(m[s[i]]>0)
                    m[s[i]]--;
                i++;
            }
            m[s[j]]++;
            ans = max(ans, j-i+1);
        }
        return ans==INT_MIN?0:ans;
    }
    
};