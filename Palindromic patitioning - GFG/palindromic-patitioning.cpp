// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[501][501];
    bool isPlaindrom(string s, int low, int high)
    {
        while(low<high)
        {
            if(s[low]!=s[high])
            {
                return 0;
            }
            low++;
            high--;
        }
        return 1;
    }
    int solve(string s, int i, int j)
    {
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(isPlaindrom(s, i, j)==true)
            return 0;
        int ans = INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int left = (dp[i][k]==-1 ? solve(s, i, k):dp[i][k]);
            int right = (dp[k+1][j]==-1 ? solve(s, k+1, j):dp[k+1][j]);
            int temp = 1 + left+ right;
            ans = min(temp , ans);
        }
        return dp[i][j] =  ans;
            
    }

    int palindromicPartition(string str)
    {
        // code here
        memset(dp, -1, sizeof(dp));
        int n = str.size();
        return solve(str, 0, n-1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends