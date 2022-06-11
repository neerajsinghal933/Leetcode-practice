class Solution {
public:
    typedef long long ll;
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        ll sum = 0;
        for(int x:nums)
            sum += x;
        ll t = sum - x;
        if(t<0)
            return -1;
        if(t==0)
            return n;
        unordered_map<ll, ll>m;
        ll cnt = 0;
        ll ans = INT_MIN;
        for(ll i=0;i<n;i++)
        {
            cnt += nums[i];
            if(cnt==t)
            {
                ans = max(ans, i+1);
                // cout<<ans<<" ";
            }
            else
            {
                ll temp = cnt-t;
                if(m[temp]!=0)
                    ans = max(ans, i-m[temp]+1);
            }
            m[cnt] = i+1;
        }
        if(ans==INT_MIN)//?-1:ans;
            return -1;
        return n-ans;
    }
};