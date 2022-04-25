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
        int sum = 0;
        for(int i=0;i<n;i++)
        sum += arr[i];
        if(sum&1)
        return 0;
        return fun(arr, n-1, sum/2)==true?1:0;
    }
    
    bool fun(int arr[], int n, int k)
    {
        
        if(n<0 and k==0)
        return 1;
        if(k==0)
        return 1;
        if(n<0)
        return 0;
        if(arr[n]<=k)
           return fun(arr, n-1, k-arr[n]) or fun(arr, n-1, k);
         return fun(arr, n-1, k);
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