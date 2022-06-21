class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int>dp(n, -1);
        int ans = 0 ;
        for(int i=0;i<n;i++)
            ans = max(ans, fun(arr, d, dp, i));
        return ans;
    }
    
    int fun(vector<int>&arr, int d, vector<int>&dp, int i)
    {
        int n = arr.size();
        if(dp[i]!=-1)
            return dp[i];
        int a = 0, b = 0;
        for(int k=i-1;k>=0 and k>=i-d;k--)
        {
            if(arr[i]<=arr[k])
                break;
            a = max(a, fun(arr, d, dp, k));
        }
        
        for(int k=i+1; k<n and k<=i+d;k++)
        {
            if(arr[i]<=arr[k])
                break;
            b = max(b, fun(arr, d, dp, k));
        }
        return dp[i] = 1 + max(a, b);
    }
};