class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        if(n==1)
        {
            if(s[0]=='?')
                return "a";
            return s;
        }
        for(int i=0;i<n;i++)
        {
            if(i==0 and s[i]=='?')
            {
                if(s[i+1]=='a')
                    s[i]='b';
                else
                    s[i]='a';
                continue;
            }
            if(i==n-1 and s[i]=='?')
            {
                if(s[i-1]=='a')
                    s[i]='b';
                else
                    s[i]='a';
                continue;
            }
            if(s[i]=='?')
            {
                while(1)
                {
                    s[i] = rand()%26 + 'a';
                    if(s[i]!=s[i-1] and s[i]!=s[i+1])
                        break;
                }
                // s[i] = (s[i-1] + 1)%26 + 'a';
            }
        }
        return s;
    }
};