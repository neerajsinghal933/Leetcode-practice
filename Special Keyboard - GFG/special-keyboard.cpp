// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int optimalKeys(int n){
        // code here
        if(n<=6)
        return n;
        int cnt[n];
        for(int i=1;i<=6;i++)
            cnt[i-1] = i;
        for(int i=7;i<=n;i++)
        {
            cnt[i-1] = max({2*cnt[i-4], 3*cnt[i-5], 4*cnt[i-6]});
        }
        
        return cnt[n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends