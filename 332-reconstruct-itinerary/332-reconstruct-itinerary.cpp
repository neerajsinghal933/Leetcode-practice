class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, multiset<string>>mp;
        for(auto x:tickets)
            mp[x[0]].insert(x[1]);
        stack<string>st;
        vector<string>res;
        st.push("JFK");
        while(!st.empty())
        {
            string s = st.top();
            if(mp[s].empty())
            {
                res.push_back(s);
                st.pop();
            }
            else
            {
                st.push(*mp[s].begin());
                mp[s].erase(mp[s].begin());
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};