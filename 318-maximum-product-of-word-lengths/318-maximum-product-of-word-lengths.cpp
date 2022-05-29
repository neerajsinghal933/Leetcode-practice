class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        for(int i=0;i<words.size();i++)
        {
            vector<int>v(26, 0);
            string s = words[i];
            int sz1 = s.size();
            for(int j=0;j<s.size();j++)
            {
                v[s[j]-'a']++;
            }
            
            for(int k = i+1;k<words.size();k++)
            {
                int flag=1;
                string t = words[k];
                for(int p=0;p<t.size();p++)
                {
                    if(v[t[p]-'a']!=0)
                    {
                        flag=0;break;
                    }
                }
                int sz2 = t.size();
                if(flag)
                {
                    ans = max(ans, sz1 * sz2);
                }
            }
        }
        return ans;
    }
};