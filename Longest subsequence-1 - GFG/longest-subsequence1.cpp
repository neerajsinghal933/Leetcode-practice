// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int n, int a[])
    {
        // code here
        vector<int>dp(n);
        dp[0] = 1;
        for(int i=1;i<n;i++)
        {
            bool flag = false;
            for(int j=0;j<i;j++)
            {
                if(abs(a[j]-a[i])==1)
                {
                    flag = true;
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            if(!flag)
                dp[i] = 1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends