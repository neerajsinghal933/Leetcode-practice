class Solution {
public:
    int ans = INT_MIN;
    int maxProduct(string s) {
        string s1 = "";
        string s2 = "";
        fun(s, s2, s1, 0);
        return ans;
    }
    
    void fun(string& s, string& s1, string& s2, int i)
    {
        if(i==s.size() and isPalin(s1) and isPalin(s2))
        {
            ans = max(ans, (int)s1.size() * (int)s2.size());
            return;
        }
        if(i==s.size())
            return;
        s1.push_back(s[i]);
        fun(s, s1, s2, i+1);
        s1.pop_back();
        
        s2.push_back(s[i]);
        fun(s, s1, s2, i+1);
        s2.pop_back();
        
        
        fun(s, s1, s2, i+1);
    }
    
    bool isPalin(string& s)
    {
        int n = s.size();
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-1-i])
                return false;
        }
        return true;
    }
};