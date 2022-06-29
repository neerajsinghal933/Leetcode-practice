class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        stack<int>st;
        unordered_map<int, int>m;
        for(int i:nums2)
        {
            while(!st.empty() and st.top()<i)
            {
                m[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        for(int i:nums1)
        {
            ans.push_back(m[i]?m[i]:-1);
        }
        return ans;
    }
};