class Solution {
public:
    int ans = INT_MIN;
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        for(int i=1;i<n;i++)
            cardPoints[i] += cardPoints[i-1];
        if(n==k)
            return cardPoints[n-1];
        int t = n-k;
        int mn = cardPoints[t-1];
        for(int i=t;i<n;i++)
            mn = min(mn, cardPoints[i] - cardPoints[i-t]);
        return cardPoints[n-1] - mn;
    }
    
    
};