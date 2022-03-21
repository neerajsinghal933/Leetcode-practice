class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int>m;
        for(int i=0;i<s.size();i++)
        {
            
            m[s[i]] = i+1;
        }
        if(s.size()==1)
            return {1};
        vector<int>ans;
        int pos = 1;
        int cnt = 1;
        int tar = m[s[0]];
        for(int i=0;i<s.size();i++)
        {
            if(i==tar-1)
            {
                // cnt++;
                ans.push_back(cnt);
                cnt=1;
                // cout<<i;
                if(i!=s.size()-1)
                    tar = m[s[i+1]];
            }
            else
            {
                cnt++;
                tar = max(tar, m[s[i]]);
            }
        }
        return ans;
    }
};