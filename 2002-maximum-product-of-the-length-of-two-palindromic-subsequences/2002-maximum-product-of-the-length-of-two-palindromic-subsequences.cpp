class Solution {
public:
    int ans = INT_MIN;
    int maxProduct(string s) {
        int n = s.size();
        string s1="", s2="";
        fun(s, s1, s2, 0);
        return ans;
    }
    
    void fun(string &s, string &s1, string &s2, int idx)
    {
        if(idx==s.size() and isPalin(s1) and isPalin(s2))
        {
            ans = max(ans, (int)s1.size() * (int)s2.size());
            return;
        }
        if(idx==s.size())
            return;
        s1.push_back(s[idx]);
        fun(s, s1, s2, idx+1);
        s1.pop_back();
        
        s2.push_back(s[idx]);
        fun(s, s1, s2, idx+1);
        s2.pop_back();
        
        fun(s, s1, s2, idx+1);
    }
    
    bool isPalin(string &s)
    {
        int i = 0, k = s.size()-1;
        while(i < k)
        {
            if(s[i++] != s[k--])
                return false;
        }
        return true;
        
    }
};