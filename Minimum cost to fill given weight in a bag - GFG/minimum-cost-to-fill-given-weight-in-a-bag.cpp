// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	
	
	
	
	int fun(int v[], int n, int w, vector<vector<int>>&dp)
    {
        if(n==-1 and w==0)
        {
            return 0;
        }
        if(n==-1)
            return 1e9;
        if(w==0)
            return 0;
        if(dp[n][w]!=-1)
            return dp[n][w];
        if(n+1>w or v[n]==-1)
            return fun(v, n-1, w, dp);
        return dp[n][w] = min(fun(v, n-1, w, dp), v[n] + fun(v, n, w-(n+1), dp));
    }
	
	
	
	
	int minimumCost(int v[], int n, int w) 
	{ 
        // Your code goes here
        vector<vector<int>>dp(n+1, vector<int>(w+1, -1));

        int ans = fun(v, n-1, w, dp);
        if(ans>=1e9)
            return -1;
        else
            return ans;
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends