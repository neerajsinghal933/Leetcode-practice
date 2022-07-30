class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>>res;
        vector<string>curr;
        fun(s, curr, 0, res);
        return res;
    }
    
    void fun(string &s, vector<string>&curr, int idx, vector<vector<string>>&res)
    {
        if(idx==s.size())
        {
            res.push_back(curr);
            return;
        }
        for(int i=0;i<s.size()-idx;i++)
        {
            if(isSafe(s, idx, i+idx))
            {
                curr.push_back(s.substr(idx, i+1));
                fun(s, curr, i+idx+1, res);
                curr.pop_back();
            }
        }
    }
    
    bool isSafe(string &s, int low, int high)
    {
        
        while(low<high)
        {
            if(s[low]!=s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
};