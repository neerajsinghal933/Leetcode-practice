// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        // if(arr[0]==0 and n!=1)
        //     return -1;
        if(n==1 and arr[0]==0)
            return 0;
        int ans = 0, curr=0, end = 0;
        for(int i=0;i<n;i++)
        {
            curr = max(curr, i + arr[i]);
            if(end==i)
            {
                ans++;end = curr;
            }
            if(end>=n-1)
                return ans;
        }
        return -1;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends