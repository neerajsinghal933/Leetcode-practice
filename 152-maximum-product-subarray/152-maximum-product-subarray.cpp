class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        int mx = nums[0];
        int mn = nums[0];
        // int ans = nums[0];
        int cmx = nums[0];
        int cmin = nums[0];
        for(int i=1;i<n;i++)
        {
            int a = max({nums[i], cmx*nums[i], cmin*nums[i]});
            int b = min({nums[i], cmx*nums[i], cmin*nums[i]});
            mx = max(mx, a);
            mn = min(mn, b);
            cmx = a;
            cmin = b;
            
            // mn = min({nums[i],a,b});
            // mx = max({nums[i], a, b});
            // mx = max(nums[i], nums[i]*mx);
            // mn = min(nums[i], nums[i]*mn);
            // cout<<mx<<" "<<mn<<endl;
            // ans = max(mn,mx);
            // ans = max({ans, mx, mn});
        }
        return mx;
    }
};