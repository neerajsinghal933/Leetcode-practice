// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{

	public:
	int minCoins(int coins[], int m, int n) 
	{ 
	    // Your code goes here
	    sort(coins, coins + m);
	    
	    vector<vector<long long>>v(m+1, vector<long long>(n+1, 0));
	    
	    for(long long j=0;j<=n;j++)
	        v[0][j]  = INT_MAX;
	        
	   for(long long i=1;i<=m;i++)
	   {
	       for(long long j=1;j<=n;j++)
	       {
	           if(coins[i-1 ] > j)
	            v[i][j] = v[i-1][j];
	            else
	            {
	                v[i][j] = min(v[i-1][j], 1+v[i][j-coins[i-1]]);
	            }
	       }
	   }
	   
	   return v[m][n] == INT_MAX ? -1 : v[m][n];
	} 
	  
};
// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends