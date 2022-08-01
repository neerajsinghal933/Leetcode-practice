class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<pair<char, int>>st;
        int ans = 0;
        for(int i=0;i<colors.size(); i++)
        {
            char c = colors[i];
            if(st.empty())
                st.push({c, neededTime[i]});
            else{
                if(st.top().first==c)
                {
                    pair<char, int>t = st.top();
                    // st.pop();
                    if(t.second<neededTime[i])
                    {
                        ans += t.second;
                        // cout<<ans<<" ";
                        st.pop();
                        st.push({c, neededTime[i]});
                    }
                    else
                    {
                        // cout<<"k";
                        ans += neededTime[i];
                    }
                }
                else
                    st.push({c, neededTime[i]});
            }
        }
        return ans;
    }
};