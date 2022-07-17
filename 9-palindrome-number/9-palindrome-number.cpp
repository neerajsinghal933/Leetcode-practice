class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return 0;
        if(x==0)
            return 1;
        string s = to_string(x);
        int n = s.size();
        for(int i=0;i<s.size()/2;i++)
        {
            if(s[i]!=s[n-i-1])
                return false;
        }
        return true;
    }
};