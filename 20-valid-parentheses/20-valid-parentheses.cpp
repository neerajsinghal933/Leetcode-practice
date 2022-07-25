class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c:s)
        {
            if(c=='(' or c=='{' or c=='[')
            {
                st.push(c);
                continue;
            }
            if(c==')')
            {
                if(!st.empty() and st.top()=='(')
                    st.pop();
                else
                    return false;
            }
            if(c=='}')
            {
                if(!st.empty() and st.top()=='{')
                    st.pop();
                else
                    return false;
            }
            if(c==']')
            {
                if(!st.empty() and st.top()=='[')
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};