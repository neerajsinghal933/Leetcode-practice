class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int mx = INT_MIN;
        if(n==1)
            return nums[0];
        int first=1, second=1, flag=true;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                first = 1;
                second = 1;
                flag=true;
            }
            else
            {
                if(nums[i]<0 and flag)
                {
                    flag=false;
                    first *= nums[i];
                }
                else
                {
                    if(!flag)
                        second *= nums[i];
                    first *= nums[i];
                    ans = max(ans, max(first, second));
                }
                // first *= nums[i];
                // ans = max(ans, max(first, second));
            }
            
            mx = max(mx, nums[i]);
        }
        
        if(mx<0 and ans <0)
            return mx;
        return max(mx, ans);
        
    }
};