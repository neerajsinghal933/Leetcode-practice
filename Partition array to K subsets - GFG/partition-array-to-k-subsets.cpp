// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         int sum = 0;
         for(int i=0;i<n;i++)
            sum += a[i];
        if(sum%k!=0)
            return 0;
        sum /= k;
        vector<int>vis(n, 0);
        return fun(a, n, k, sum, 0, 0, vis);
    }
    
    bool fun(int a[], int n, int k, int sum, int idx, int t, vector<int>&vis)
    {
        // cout<<"l";
        if(k==0){
            return true;
        }
        if(t==sum){
            // cout<<"k";
            return fun(a, n, k-1, sum, 0, 0, vis);
        }
        for(int i=idx;i<n;i++)
        {
            if(!vis[i] and a[i] + t<=sum)
            {
                vis[i] = 1;
                if(fun(a, n, k, sum, idx+1, a[i] + t, vis)==true)
                    return true;
                vis[i] = 0;
            }
        }
        return false;
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
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends