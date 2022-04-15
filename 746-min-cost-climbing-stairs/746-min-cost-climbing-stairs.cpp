class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        
        vector<int> dp(n+2); 
        //since we reach end at n
        dp[n]=0;
        dp[n+1]=0; 
        
        for(int i=n-1;i>=0;i--)
        {
            //i will get the min cost from the next 2 steps
            dp[i]=min(dp[i+1],dp[i+2])+cost[i];
        }
        
        //since i can start from step0  and step1 
        //i will choose the min cost step
        return min(dp[0],dp[1]);
    }
};