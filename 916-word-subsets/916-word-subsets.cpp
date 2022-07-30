class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>res;
        vector<int>maxFreq(26, 0);
        for(string s:words2)
        {
            vector<int>freq = fun(s);
            for(int i=0;i<26;i++)
                maxFreq[i] = max(maxFreq[i], freq[i]);
        }
        // for(int i=0;i<26;i++)
        //     cout<<maxFreq[i]<<" ";// = max(maxFreq[i], freq[i]);
        for(string s:words1)
        {
            vector<int>freq = fun(s);
            bool flag = false;
            for(int i=0;i<26;i++)
            {
                if(freq[i]<maxFreq[i])
                {
                    flag = 1;
                    break;
                }
            }
            if(!flag)
                res.push_back(s);
        }
        return res;
    }
    
    vector<int> fun(string &s)
    {
        // int n = s.size();
        vector<int>freq(26, 0);
        for(char c:s)
            freq[c-'a']++;
        return freq;
    }
};