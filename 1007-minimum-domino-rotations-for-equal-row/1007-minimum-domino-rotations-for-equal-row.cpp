class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int ans = INT_MAX;
        for(int i=1;i<=6;i++)
        {
            int cnt = 0;
            for(int j=0;j<n;j++)
            {
                if(tops[j]==i or bottoms[j]==i)
                    cnt++;
            }
            if(cnt==n)
            {
                int temp = max(count(tops.begin(), tops.end(), i), count(bottoms.begin(), bottoms.end(), i));
                ans = min(ans, n-temp);
                    
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};