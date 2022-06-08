// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &a,int n){
        sort(a.begin(),a.end());
       int count = 1;
       int i=0, j=n-1;
       long long int sum = 0, sum1 = a[j];
       while(i<j) {
           sum = sum + a[i];
           if(sum == 0 && sum1 == 0) {        
               count++;
           }
           else if(sum >= sum1) {
               sum1 = sum1 + a[--j];        
               count++;
           }
           i++;
       }
       return count;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}  // } Driver Code Ends