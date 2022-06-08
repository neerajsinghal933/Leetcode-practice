// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int v[], int n, int k)
    {
        // Write Your Code here
        sort(v, v+n);
        int i=0, j=n-1;
        int sum = 0;
        while(i<=j)
        {
            sum += v[i];
            j-=k;
            i++;
            // cout<<sum<<" ";
        }
        // cout<<endl;
        i=0, j=n-1;
        int sum1 = 0;
        while(i<=j)
        {
            sum1 += v[j];
            i += k;
            j--;
        }
        return {sum, sum1};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends