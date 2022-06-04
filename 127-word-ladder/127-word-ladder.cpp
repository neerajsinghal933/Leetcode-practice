class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        queue<string>q;
        q.push(beginWord);
        int wordSize = beginWord.size();
        
        unordered_set<string>word;
        for(auto s:wordList)
            word.insert(s);
        if(word.find(endWord)==word.end())
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
                    for(int c='a';c<='z';c++)
                    {
                        s[j] = c;
                        if(s==endWord)
                            return len+1;
                        if(word.find(s)==word.end())
                            continue;
                        word.erase(s);
                        q.push(s);
                    }
                    s[j] = temp;
                }
            }
        }
        return 0;
        
    }
};