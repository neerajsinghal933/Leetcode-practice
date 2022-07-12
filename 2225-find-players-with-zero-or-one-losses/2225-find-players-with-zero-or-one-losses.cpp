class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int>m;
        for(int i=0;i<matches.size();i++)
        {
            m[matches[i][1]]--;
        }
        vector<int>ans1, ans2;
        for(int i=0;i<matches.size();i++)
        {
            int a = matches[i][0];
            if(m[a]==0)
            {
                ans1.push_back(a);
                m[a]++;
            }
            // m[matches[i][1]]--;
        }
        for(auto x:m)
        {
            if(x.second==-1)
                ans2.push_back(x.first);
        }
        sort(ans1.begin(), ans1.end());
        return {ans1, ans2};
        
    }
};