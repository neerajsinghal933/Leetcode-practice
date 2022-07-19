class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for(auto x:dictionary)
        {
            int l = 0, h = 0;
            while(l<x.size() and h<s.size())
            {
                if(x[l] == s[h])
                    l++;
                h++;
            }
            if(l==x.size())
            {
                if(ans.size()<x.size())
                    ans = x;
                if(ans.size()==x.size())
                    ans = min(ans, x);
            }
        }
        return ans;
    }
};