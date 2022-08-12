class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt = 1;
        int n = nums.size();
        if(n==1)
            return 0;
        int curr = nums[0];
        int mx = nums[0];
        for(int i=1;i<n;i++)
        {
            
            mx = max(mx, i + nums[i]);
            if(i!=n-1 and curr==i)
            {
                cnt++;
                curr = mx;
            }
        }
        return cnt;
    }
};