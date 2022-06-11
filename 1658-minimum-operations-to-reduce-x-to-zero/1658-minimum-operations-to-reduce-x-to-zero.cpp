class Solution {
public:
    typedef long long ll;
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        ll sum = 0;
        for(int i:nums)
            sum += i;
        if(sum<x)
            return -1;
        ll t = sum - x;
        int i=0, j=-1;
        ll curr = 0;
        int ans = 0;
        // cout<<sum<<" "<<t;
        if(t==0)
            return n;
        for(int j=0;j<n;j++)
        {
            // j++;
            curr += nums[j];
            while(i<n and curr>t)
            {
                curr -= nums[i];
                i++;
            }
            if(curr==t)
            {
                // cout<<"k";
                ans = max(ans, j-i+1);
                // cout<<i<<" "<<j<<endl;
            }
        }
        if(ans==0)
            return -1;
        return n-ans;
    }
};