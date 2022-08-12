class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int st = 0;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int l =i, r = i;
            while(l>=0 and r<n and s[l]==s[r])
            {
                l--;
                r++;
            }
            if(ans < (r-l-1))
            {
                st = l+1;
                ans = r-l-1;
            }
            if(i+1==n)
                continue;
            l = i, r = i+1;
            while(l>=0 and r<n and s[l]==s[r])
            {
                l--;
                r++;
            }
            if(ans < (r-l-1))
            {
                st = l+1;
                ans = r-l-1;
            }
        }
        return s.substr(st, ans);
    }
};