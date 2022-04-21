// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int fun(vector<int>&res, int n)
    {
        int ans = INT_MIN;
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            cnt += res[i];
            ans = max(ans, cnt);
            cnt = max(0, cnt);
        }
        return ans;
    }
  
    int maximumSumRectangle(int r, int c, vector<vector<int>> m) {
        int ans = INT_MIN;
        for(int i=0;i<r;i++)
        {
            vector<int>res(c);
            for(int j=i;j<r;j++)
            {
                
                for(int k=0;k<c;k++)
                {
                    res[k] += m[j][k];
                }
                ans = max(ans, fun(res, c));
            }
        }
        return ans;
        // code here
    }
    
    
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends