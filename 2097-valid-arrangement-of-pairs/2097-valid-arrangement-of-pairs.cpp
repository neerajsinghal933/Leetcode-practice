class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, stack<int>>mp;
        unordered_map<int, int>cnt;
        
        for(auto x:pairs)
        {
            cnt[x[0]]++;
            cnt[x[1]]--;
            mp[x[0]].push(x[1]);
        }
        
        int start = mp.begin()->first;
        for(auto x:cnt)
        {
            if(x.second == 1)
            {
                start = x.first;
                break;
            }
        }
        
        stack<int>st;
        st.push(start);
        vector<vector<int>>res;
        while(!st.empty())
        {
            int u = st.top();
            if(!mp[u].empty())
            {
                int v = mp[u].top();
                mp[u].pop();
                st.push(v);
                u = v;
            }
            else
            {
                st.pop();
                if(st.empty())
                {
                    reverse(res.begin(), res.end());
                    return res;
                }
                int v = st.top();
                res.push_back({v, u});
            }
        }
        return res;
    }
};