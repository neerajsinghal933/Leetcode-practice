class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9+7;
        int n = arr.size();
        stack<int>st;
        vector<int>left(n, n), right(n, -1);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and arr[st.top()]>=arr[i])
                st.pop();
            if(!st.empty())
                left[i] = st.top();
            st.push(i);
        }
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() and arr[s.top()]>arr[i])
                s.pop();
            if(!s.empty())
                right[i] = s.top();
            s.push(i);
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<left[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++)
        // {
        //     cout<<right[i]<<" ";
        // }
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            ans += (long long)arr[i] * ((left[i]-i) * (i - right[i]));
            // cout<<ans<<" ";
            ans %= mod;
        }
        
        return ans;
    }
};