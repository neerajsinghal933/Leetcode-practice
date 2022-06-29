class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        int idx = max_element(nums.begin(), nums.end()) - nums.begin();
        stack<int>st;
        vector<int>ans(n);
        for(int i=idx;i>=0;i--)
        {
            while(!st.empty() and st.top()<=nums[i])
                st.pop();
            if(st.empty())
            {
                ans[i] = -1;
            }
            else
                ans[i] = st.top();
            st.push(nums[i]);
        }
        for(int i=n-1;i>idx;i--)
        {
            while(!st.empty() and st.top()<=nums[i])
                st.pop();
            if(st.empty())
            {
                ans[i] = -1;
            }
            else
                ans[i] = st.top();
            st.push(nums[i]);
        }
        return ans;
    }
};