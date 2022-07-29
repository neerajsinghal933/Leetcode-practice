class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
        for(string s:words)
        {
            unordered_map<char, char>m1;
            unordered_map<char, int>m2;
            bool flag = 0;
            for(int i=0;i<s.size();i++)
            {
                char c = s[i];
                if(m2[c]==0 and !m1[pattern[i]])
                {
                    m2[c] = 1;
                    // m2[pattern[i]] = 1;
                    m1[pattern[i]] = c;
                    // m1[c] = pattern[i];
                }
                else{
                    if(m1[pattern[i]]!=c)
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if(!flag)
                res.push_back(s);
        }
        return res;
    }
};