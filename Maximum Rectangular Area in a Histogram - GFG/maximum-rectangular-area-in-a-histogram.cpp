// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<int>left(n), right(n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and arr[st.top()] >= arr[i])
                st.pop();
            if(st.empty())
                left[i] = 0;
            else
                left[i] = st.top()+1;
            st.push(i);
        }
        while(st.size())
        st.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and arr[st.top()] >= arr[i])
                st.pop();
            if(st.empty())
                right[i] = n;
            else
                right[i] = st.top();
            st.push(i);
        }
        long long res = 0;
        for(int i=0;i<n;i++)
        {
            res = max(res, (right[i] - left[i]) * arr[i]);
        }
        return res;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends