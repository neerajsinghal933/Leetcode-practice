// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string s)
	{
	    // Your code goes here
	    int sum = 0;
	    int ans = INT_MIN;
	    for(char c:s)
	    {
	        int x = -1;
	        if(c=='0')
	            x = 1;
	         sum += x;
	         ans = max(sum, ans);
	         if(sum<0)
	            sum = 0;
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends