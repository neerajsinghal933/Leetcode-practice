class Solution {
public:
    string rankTeams(vector<string>& votes) {
        unordered_map<char, vector<int>>m;
        int n = votes[0].size();
        for(int i=0;i<n;i++)
        {
            for(string c:votes)
            {
                m[c[i]].push_back(i);
            }
        }
        vector<pair<vector<int>, char>>v;
        for(auto x:m)
        {
            v.push_back({x.second, x.first});
        }
        sort(v.begin(), v.end());
        string ans = "";
        for(auto x:v)
        {
            ans += x.second;
        }
        return ans;
    }
};