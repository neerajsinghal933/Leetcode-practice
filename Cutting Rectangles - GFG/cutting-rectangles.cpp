// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<long long int> minimumSquares(long long int l, long long int b)
    {
        // code here
        // long long mn = min(l, b);
        // long long mx = max(l, b);
        // long long n = mn;
        // long long k = mx/mn;
        // long long t = mx - mn;
        long long mn = __gcd(l, b);
        long long k = (l*b)/(mn*mn);
        return {k, mn};
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int L, B;
        cin>>L>>B;
        
        Solution ob;
        vector<long long int> ans = ob.minimumSquares(L, B);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}  // } Driver Code Ends