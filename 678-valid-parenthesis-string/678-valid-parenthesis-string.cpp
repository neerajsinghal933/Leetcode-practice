class Solution {
public:
    bool checkValidString(string s) {
        int l=0, r = 0;
        for(char c:s)
        {
            if(c=='(' or c=='*')
                l++;
            else
                l--;
            if(l<0)
                return false;
        }
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]==')' or s[i]=='*')
                r++;
            else
                r--;
            if(r<0)
                return false;
        }
        return true;
        
    }
};