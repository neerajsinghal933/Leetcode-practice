class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        queue<string>q;
        q.push(beginWord);
        int wordSize = beginWord.size();
        
        unordered_set<string>st;
        for(auto s:wordList)
            st.insert(s);
        if(st.find(endWord)==st.end())
            return 0;
        int len = 0;
        while(!q.empty())
        {
            len++;
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                string s = q.front();
                q.pop();
                for(int j=0;j<wordSize;j++)
                {
                    char temp = s[j];
                    for(char c='a';c<='z';c++)
                    {
                        s[j] = c;
                        if(s==endWord)
                            return len+1;
                        if(st.find(s)==st.end())
                            continue;
                        st.erase(s);
                        q.push(s);
                    }
                    s[j] = temp;
                    
                }
            }
        }
        return 0;
    }
};