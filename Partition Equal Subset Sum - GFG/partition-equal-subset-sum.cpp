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
        if(sum & 1)
            return 0;
        sum /= 2;
        return fun(n, arr, sum);
    }
    
    bool fun(int n, int arr[], int k)
    {
        if(n==0 or k==0)
        {
            if(k==0)
                return 1;
            return 0;
        }
        if(k-arr[n-1]>=0)
            return fun(n-1, arr, k-arr[n-1]) or fun(n-1, arr, k);
        return fun(n-1, arr, k);
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