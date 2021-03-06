class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(char c:s)
        {
            if(!st.empty() and st.top()==c)
                st.pop();
            else
                st.push(c);
        }
        string ans = "";
        while(!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};