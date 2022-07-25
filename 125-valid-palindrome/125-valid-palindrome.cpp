class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for(char c:s)
        {
            if(c>='a' and c<='z')
            {
                t+=c;
                continue;
            }
            if(c>='A' and c<='Z')
            {
                t += c+32;
                continue;
            }
            if(c>='0' and c<='9')
            {
                t += c;
                continue;
            }
        }
        if(check(t))
            return true;
        return false;
    }
    
    bool check(string &s)
    {
        int n = s.size();
        int i=0, j=n-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};