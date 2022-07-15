// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int n, int sum){
        // code here
        if(sum==0 and n>1)
            return "-1";
        if(n*9<sum)
            return "-1";
            
        string ans = "";
        while(sum>9)
        {
            ans += '9';
            n--;
            sum-=9;
        }
        n--;
        ans+=to_string(sum);
        while(n--)
            ans+='0';
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends