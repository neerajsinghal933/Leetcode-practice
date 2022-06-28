class Solution {
public:
    
    
    static bool comp(int a, int b)
    {
        return a>b;
    }
    
    int minDeletions(string s) {
        vector<int>f(26, 0);
        for(char c:s)
            f[c-'a']++;
        sort(f.begin(), f.end(), comp);
        int i=0;
        for(i=0;i<26;i++)
        {
            // cout<<f[i]<<" ";
            if(f[i]==0)
                break;
        }
        map<int, int>m;
        int ans = 0;
        for(int j=0;j<i;j++)
        {
            if(m[f[j]]==0)
                m[f[j]]=1;
            else
            {
                
                int curr = f[j];
                while(curr>0 and m[curr]!=0)
                {
                    // cout<<"k";
                    curr--;
                    ans++;
                }
                m[curr]=1;
            }
        }
        return ans;
    }
};