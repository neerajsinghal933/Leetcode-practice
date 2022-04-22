// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
        // Your code goes here   
        priority_queue<int>q;
        for(int i=0;i<n;i++)
        {
            q.push(arr[i]);
        }
        int sum = 0;
        while(!q.empty())
        {
            int x = q.top();
            q.pop();
            if(!q.empty())
            {
                int y = q.top();
                if(x-y<k){
                q.pop();
                sum += x+y;
                }
            }
        }
        return sum;
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
  // } Driver Code Ends