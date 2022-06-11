// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
    // bool isSubsetSum(int n, int arr[], int sum){
    //     // code here 
    //     vector<vector<bool>>dp(n+1, vector<bool>(sum+1, false));
    //     for(int i=0;i<=n;i++)
    //     {
    //         dp[i][0] = true;
    //     }
    //     for(int i=1;i<=n;i++)
    //     {
    //         for(int j=1;j<=sum;j++)
    //         {
    //             if(arr[i-1]<=j)
    //                 dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
    //             else
    //                 dp[i][j] = dp[i-1][j];
    //         }
    //     }
    //     return dp[n][sum];
    // }
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int x=0;x<n;x++)
	        sum+=arr[x];
	    vector<vector<bool>>dp(n+1, vector<bool>(sum+1, 0));
	    for(int i=0;i<=n;i++)
	    {
	        dp[i][0] = true;
	    }
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=sum;j++)
	        {
	            if(arr[i-1]<=j)
	                dp[i][j] = dp[i-1][j] or dp[i-1][j-arr[i-1]];
	            else
	                dp[i][j] = dp[i-1][j];
	                
	        }
	    }
	    int diff = sum;
	    int curr_sum = 0;
	    for(int i=sum/2;i>=0;i--)
	    {
	        if(dp[n][i]==true)
	        {
	            diff = abs(sum-2*i);
	            break;
	        }
	    }
	    return diff;
	    
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

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends