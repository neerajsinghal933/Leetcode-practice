class Solution {
public:
    bool isPlain(string s)
    {
        int n = s.size();
        for(int i=0;i<=n/2;i++)
        {
            if(s[i]!=s[n-i-1])
                return false;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(isPlain(s))
            return 1;
        return 2;
    }
};