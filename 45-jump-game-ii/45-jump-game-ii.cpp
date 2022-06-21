class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt = 1;
        int curr = nums[0];
        int mx = nums[0];
        int n = nums.size();
        if(n==1)
            return 0;
        for(int i=1;i<n;i++)
        {
           if(curr>=n-1)
               return cnt;
            mx = max(mx, i + nums[i]);
            if(curr==i)
            {
                curr = mx;
                cnt++;
            }
        }
        return 0;
    }
};