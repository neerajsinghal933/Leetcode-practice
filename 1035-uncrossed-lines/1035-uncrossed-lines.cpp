class Solution {
public:
    int ans = 0;
    int dp[501][501];
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int cnt = 0;
        memset(dp, -1, sizeof(dp));
        fun(nums1, nums2, 0, 0);
        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            {
                if(i==0 or j==0)
                    dp[i][j] = 0;
                else
                {
                    if(nums1[i-1]==nums2[j-1])
                    {
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
            // cout<<endl;
        }
        return dp[n1][n2];
    }
    
    int fun(vector<int>&nums1, vector<int>&nums2, int x, int y)
    {
        int n = nums1.size();
        int m = nums2.size();
        if(x>=n or y>=m)
        {
            // ans = max(ans, cnt);
            return 0;
        }
        if(dp[x][y]!=-1)
            return dp[x][y];
        if(nums1[x]==nums2[y])
            return dp[x][y] = 1 + fun(nums1, nums2, x+1, y+1);
        int a=0 ,b=0;
        a = fun(nums1, nums2, x+1, y);
        b = fun(nums1, nums2, x, y+1);
        return dp[x][y] = max(a, b);
    }
};