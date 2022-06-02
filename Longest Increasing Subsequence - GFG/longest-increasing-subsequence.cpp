// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int>dp(n+1, 1);
       for(int i=n-2;i>=0;i--)
       {
           dp[i] = fun(n, a, dp, i);
       }
       return *max_element(dp.begin(), dp.end());
    }
    
    int fun(int n, int a[], vector<int>&dp, int i)
    {
        int x = 0;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]>a[i])
                x = max(x, dp[j]);
        }
        return x+1;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends