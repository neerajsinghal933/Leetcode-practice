// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int A[]) {
        // code here
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return fun(A, 0, n, k, 1, dp);
    }
    
    int fun(int a[], int idx, int n, int k, bool buy, vector<vector<vector<int>>>&dp)
    {
        if(idx==n or k==0)
        return 0;
        if(dp[idx][buy][k]!=-1)
        return dp[idx][buy][k];
        
        if(buy)
        {
           return dp[idx][buy][k] = max(-a[idx] + fun(a, idx+1, n, k, !buy, dp), fun(a, idx+1, n, k, buy, dp)); 
        }
        else
        return dp[idx][buy][k] = max(a[idx] + fun(a, idx+1, n, k-1, !buy, dp), fun(a, idx+1, n, k, buy, dp));
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends