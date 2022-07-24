class Solution {
public:
    int strStr(string haystack, string needle) {
        int n  = haystack.size();
        int m  = needle.size();
        for(int i=0;i+m<=n;i++)
        {
            string  t = haystack.substr(i, m);
            if(t==needle)
                return i;
        }
        return -1;
    }
};