// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a, a+n);
        for(int i=0;i<n;i++)
        {
            if(a[i]<0 and k>0)
            {
                k--;
                a[i] = -1 * a[i];
            }
            if(k==0)
                break;
        }
        long long sum = 0;
        for(int i=0;i<n;i++)
            sum += a[i];
        if(k>0)
        {
            if(k%2==0)
                return sum;
            long long x = *min_element(a, a+n);
            sum -= 2*x;
            return sum;
            
        }
        return sum;
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}  // } Driver Code Ends