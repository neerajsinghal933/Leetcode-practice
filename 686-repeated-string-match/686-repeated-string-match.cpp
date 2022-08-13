class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        
        int cnt = m/n;
        if(m%n!=0)
        cnt++;
        int ans = cnt;
        string t = "";
        while(cnt)
        {
            t += a;
            cnt--;
        }
        if(check(t, b))
            return ans;
        t += a;
        if(check(t, b))
            return ans+1;
        return -1;
    }
    
    bool check(string &a, string &b)
    {
        int n = a.size();
        int m = b.size();
        for(int i=0;i+m<=n;i++)
        {
            string t = a.substr(i, m);
            if(t==b)
                return true;
        }
        return false;
    }
};