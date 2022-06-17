class Solution {
public:
    bool checkInclusion(string p, string s) {
        unordered_map<char, int>m;
        if(p.size()>s.size())
            return false;
        for(char c:p)
            m[c]++;
        int n = s.size();
        int k = p.size();
        if(k>n)
            return "-1";
        string ans = "-1";
        int ans_sz = INT_MAX;
        int j=0, matched = 0;
        for(int i=0;i<n;i++)
        {
            if(m.find(s[i])!=m.end())
            {
                m[s[i]]--;
                if(m[s[i]]>=0)
                    matched++;
                while(matched==k)
                {
                    if(i-j+1<ans_sz)
                    {
                        ans_sz = i-j+1;
                        ans = s.substr(j, i-j+1);
                    }
                    if(m.find(s[j])!=m.end())
                    {
                        m[s[j]]++;
                        if(m[s[j]]>0)
                            matched--;
                    }
                    j++;
                }
            }
        }
        if(ans=="-1")
            return false;
        return ans.size()==k;
    }
};