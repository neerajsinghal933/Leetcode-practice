class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.size();
        int m = b.size();
        if(check(a, b))
            return 1;
        string g = a + a;
        if(check(g, b))
            return 2;
        int cnt = 0;
        if(n>=m)
        {
            
            
            // cout<<t;
            
            return -1;
        }
        // cout<<"k";
        int i=0;
        int flag = 0;
        for(i=0;i+n<=m;i++)
        {
            string t = b.substr(i, n);
            if(t==a){
                flag = 1;
                break;
            }
        }
        if(i>n)
            return -1;
        // cout<<"J";
        string u = a.substr(n-i);
        string v = b.substr(0, i);
        if(v.size())
            cnt++;
        if(u!=v)
            return -1;
        // cout<<"P\n";
        // cout<<cnt<<" ";
        int rem = (m - i);
        string t = b.substr(i);
        // cout<<t;
        i=0;
        for(i=0;i+n<=t.size();i+=n)
        {
            if(t.substr(i, n)!=a)
                return -1;
            cnt++;
        }
        // cout<<" "<<i;
        if(i>=t.size())
            return cnt;
        // cout<<"A";
        // cout<<endl;
        // cout<<cnt;
        
        t = t.substr(i);
        int k = t.size();
        
        if(a.substr(0, k)==t)
            return cnt+1;
        return -1;
        
        
    }
    
    bool check(string &a, string &b)
    {
        int n = a.size();
        int m = b.size();
        for(int i=0;i+m<=n;i++)
        {
            string t = a.substr(i, m);
            if(b==t){
                // cout<<i;
                return true;
            }
        }
        // cout<<"k";
        return false;
    }
};