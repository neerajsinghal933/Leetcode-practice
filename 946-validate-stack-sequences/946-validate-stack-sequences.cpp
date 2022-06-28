class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0;
        stack<int>st;
        for(int x:pushed)
        {
            st.push(x);
            while(!st.empty() and st.top()==popped[i])
            {
                i++;
                st.pop();
            }
        }
        return i==popped.size();
    }
};