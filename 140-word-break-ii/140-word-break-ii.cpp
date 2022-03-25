class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>res;
        string temp = "";
        int n = wordDict.size();
         fun(s, wordDict, "", res);
        return res;
    }
    
    void fun(string s, vector<string>&wordDict, string temp, vector<string>&res)
    {
        int sz = s.size();
        for(int i=1;i<=sz;i++)
        {
            string t = s.substr(0, i);
            if(find(wordDict.begin(), wordDict.end(), t)!=wordDict.end())
            {
                if(i==sz)
                {
                    temp += t;
                    res.push_back(temp);
                    
                }
                fun(s.substr(i, sz-1), wordDict, temp + t + " ", res);
            }
        }
        
    }
};