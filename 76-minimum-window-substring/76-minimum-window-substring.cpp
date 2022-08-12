class Solution {
public:
    
    bool check(unordered_map<char, int>&tmp, unordered_map<char, int>&smp)
    {
        for(auto x:tmp)
        {
            if(smp[x.first] < x.second)
                return false;
        }
        return true;
    }
    
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        unordered_map<char, int>smp, tmp;
        for(int i=0;i<n;i++)
        {
            smp[s[i]]++;
            tmp[t[i]]++;
        }
        int begin=-1, end=-1;
        int res = INT_MAX;
        bool flag = false;
        if(check(tmp, smp))
        {
            flag=true;
            begin=0;
            end = n-1;
            res = n;
            return s.substr(0, n);
        }
        int i=0;
        for(int j=n;j<m;j++)
        {
            smp[s[j]]++;
            if(!flag)
            {
                if(check(tmp, smp))
                    flag=1;
            }
            if(flag)
            {
                while(smp[s[i]]>tmp[s[i]])
                {
                    smp[s[i]]--;
                    i++;
                }
                if(j-i+1<res)
                {
                    res = j-i+1;
                    begin = i;
                    end = j;
                }
            }
        }
        if(begin==-1)
            return "";
        return s.substr(begin, res);
    }
};