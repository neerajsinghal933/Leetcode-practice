// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int sum = 0, x;
	    int ans = INT_MIN;
	    for(char c:S)
	    {
	        if(c=='0'){
	            x=1;
	        }
	         else
	         {
	            x=-1;
	         }
	         sum += x;
	         ans = max(ans, sum);
	         if(sum<0)
	            sum=0;
	         
	    }
	   // if(!flag1 or !flag2)
	   //     return 0;
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