class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<string, bool>m;
        int cnt = 0;
        for(string x:words)
        {
            if(m.find(x)!=m.end())
            {
                cnt += m[x];
                // if(m[x])
                //     cout<<x<<" ";
                continue;
            }
            m[x] = check(s, x);
            cnt += m[x];
            // if(m[x])
            //     cout<<x<<" ";
        }
        return cnt;
    }
    
    bool check(string &s, string &x)
    {
        int n = s.size();
        int m = x.size();
        int i, j;
        for(i=0, j=0; i<n and j<m; i++)
        {
            if(s[i]==x[j])
                j++;
        }
        return j==m;
    }
};