// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long int findMaxProduct(vector<int>&arr, int n){
        //Write your code here  
         long long ans = 1;
         long long mod = 1e9+7;
	    int neg = 0, zero = 0, max_neg = INT_MIN;
	    if(n==1)
	        return arr[0];
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]==0)
	        {
	            zero++;
	            continue;
	        }
	        if(arr[i]<0)
	        {
	            neg++;
	            max_neg = max(max_neg, arr[i]);
	        }
	        ans = (ans*arr[i])%mod;
	    }
	    if(zero==n)
	        return 0;
	    if(ans < 0 and neg>0 and zero>0 and neg + zero==n)
	        return 0;
	   if(ans<0)
	    ans /= max_neg;
	    return ans;
    }
};



// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends