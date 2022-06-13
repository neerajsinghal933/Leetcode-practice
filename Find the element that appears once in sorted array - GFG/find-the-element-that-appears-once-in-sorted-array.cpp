// { Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        int l=0, h=n-1;
        while(l<h)
        {
            int mid = (l+h)/2;
            if(arr[mid]!=arr[mid+1] and arr[mid]!=arr[mid-1])
                return arr[mid];
            else if(arr[mid]==arr[mid-1])
            {
                if(mid%2==1)
                {
                    l = mid+1;
                }
                else
                    h = mid-1;
            }
            else
            {
                if(mid%2==1)
                    h = mid-1;
                else
                    l = mid+1;
            }
        }
        return arr[l];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}  // } Driver Code Ends