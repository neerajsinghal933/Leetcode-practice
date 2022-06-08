// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int a[])
    {
        // code here
        int sum = 0;
        for(int i=0;i<n;i++)
            sum += a[i];
        if(sum & 1)
            return 0;
        return fun(n-1, a, sum/2, 0);
    }
    
    bool fun(int n, int a[], int k, int curr)
    {
        if(n==0 and k!=curr)
            return 0;
        if(k==curr)
            return 1;
        if(curr + a[n-1] <= k)
            return fun(n-1, a, k, curr +a[n-1]) or fun(n-1, a, k, curr);
        return fun(n-1, a, k, curr);
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