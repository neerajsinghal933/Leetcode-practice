// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> specialXor(int n, int q, int a[], vector<int> query[])
    {
        // code here
        int x = 0;
        for(int i=1;i<n;i++)
            a[i] ^= a[i-1];
        x = a[n-1];
        vector<int>ans;
        for(int i=0;i<q;i++)
        {
            int t = x;
            int l = query[i][0]-1;
            int r = query[i][1]-1;
            ans.push_back(x ^ a[r] ^ a[l-1]);
        }
        return ans;
    }
}; 

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, Q;
        cin>>N>>Q;
        int a[N];
        for(int i = 0;i < N;i++)
            cin>>a[i];
        int l, r;
        vector<int> query[Q];
        for(int i = 0;i < Q;i++){
            cin>>l>>r;
            query[i].push_back(l);
            query[i].push_back(r);
        }
        
        Solution ob;
        vector<int> ans = ob.specialXor(N, Q, a, query);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}  // } Driver Code Ends