class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i=0, j=0;
        int ans = INT_MIN;
        map<int, int>m;
        int score = 0;
        for(j=0;j<n;j++)
        {
            while(m[nums[j]]!=0)
            {
                score -= nums[i];
                m[nums[i]]--;
                i++;
            }
            m[nums[j]]++;
            score += nums[j];
            ans = max(ans, score);
        }
        return ans;
        
    }
};