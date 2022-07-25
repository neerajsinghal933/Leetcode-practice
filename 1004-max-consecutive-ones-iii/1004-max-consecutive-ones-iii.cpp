class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0, j=0;
        int ans = 0, cnt =0;
        map<int, int>m;
        while(i<n)
        {
            if(nums[i]==0)
                cnt++;
            while(cnt>k)
            {
                if(nums[j]==0)
                {
                    
                    cnt--;
                }
                j++;
            }
            ans = max(ans, i-j+1);
            i++;
        }
        return ans;
    }
};