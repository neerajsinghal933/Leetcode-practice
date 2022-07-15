class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>>st;
        for(char c:s)
        {
            if(!st.empty() and st.top().first == c)
            {
                int n = st.top().second;
                if(n==k-1)
                {
                    while(n--)
                        st.pop();
                }
                else
                    st.push({c, n+1});
            }
            else
                st.push({c, 1});
        }
        string ans = "";
        while(!st.empty())
        {
            ans += st.top().first;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};