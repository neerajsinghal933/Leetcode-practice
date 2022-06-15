class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // sort(words.begin(), words.end());
        sort(words.begin(), words.end(), [](const string &l, const string &r) { return l.size() < r.size(); });
        unordered_map<string, int>m;
        int res = 1;
        for(string s:words)
        {
            m[s] = 1;
            for(int i=0;i<s.size();i++)
            {
                string temp = s.substr(0, i) + s.substr(i+1);
                if(m.find(temp)!=m.end())
                {
                    m[s] = max(m[s], 1 + m[temp]);
                    res = max(res, m[s]);
                }
            }
        }
        return res;
    }
};