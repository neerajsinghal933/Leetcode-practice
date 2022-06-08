// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    static bool comp(int a, int b)
    {
        return a>b;
    }
    int minimumCostOfBreaking(vector<int> x, vector<int> y, int m, int n){
        //Write your code here
        
        sort(x.begin(), x.end(), comp);
        sort(y.begin(), y.end(), comp);
        
        int i=0, j=0;
        int cntX=1, cntY=1;
        int ans = 0;
        while(i<m and j<n)
        {
            if(x[i]>=y[j])
            {
                cntY += 1;
                ans += x[i] * cntX;
                i++;
            }
            else
            {
                cntX += 1;
                ans += y[j] * cntY;
                j++;
            }
        }
        while(i<m)
        {
            ans += x[i] * cntX;
            i++;
        }
        while(j<n)
        {
            ans += y[j] * cntY;
            j++;
        }
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
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m - 1, n - 1);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends