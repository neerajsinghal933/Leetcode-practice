// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int count( int coin[], int m, int n )
    {
    //   sort(coin, coin+m);
       vector<vector<long long>>v(m+1, vector<long long>(n+1, 0));
       
       for(long long i=0;i<=m;i++)
       {
           v[i][0] = 1;
       }
       
       for(long long i=1;i<=m;i++)
       {
           for(long long j=1;j<=n;j++)
           {
               if(coin[i-1] > j)
                    v[i][j] = v[i-1][j];
                else
                {
                    v[i][j] = v[i-1][j] + v[i][j-coin[i-1]];
                }
           }
       }
    //   for(int i=0;i<=m;i++)
    //   {
    //       for(int j=0;j<=n;j++)
    //       {
    //           cout<<v[i][j]<<" ";
    //       }
    //       cout<<'\n';
    //   }
        return v[m][n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends