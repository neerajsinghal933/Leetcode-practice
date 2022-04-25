// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minTime(int s1, int s2, int n){
        // code here
        if(s1>s2)
        swap(s1, s2);
        
        int s = s1;
        int e = s2*n;
        int ans = 0;
        while(s<=e)
        {
            int mid = s + (e-s) / 2;
            int count = (mid/s1) + (mid/s2);
            if(count>=n)
                {
                    ans = mid;
                    e = mid-1;
                }
            else
                s = mid+1;
        }
        return ans;
    }
    
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S1, S2, N;
        cin>>S1>>S2>>N;
        
        Solution ob;
        cout<<ob.minTime(S1, S2, N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends