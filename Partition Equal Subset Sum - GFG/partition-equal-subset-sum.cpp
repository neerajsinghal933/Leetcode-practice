// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum = accumulate(arr, arr+n, 0);
        if(sum&1)
            return 0;
        sum /= 2;
        return fun(n, arr, sum);
    }
    
    bool fun(int n, int arr[], int s)
    {
        vector<vector<int>>dp(n+1, vector<int>(s+1, 0));
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=s;j++)
            {
                if(arr[i-1]<=j)
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][s];
        // if(n==0 or s==0)
        // {
        //     if(s==0)
        //         return true;
        //     return false;
        // }
        // bool p = false;
        // if(arr[n-1]<=s)
        //     p =fun(n-1, arr, s-arr[n-1]);
        // bool q = fun(n-1, arr, s);
        // return p or q;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends