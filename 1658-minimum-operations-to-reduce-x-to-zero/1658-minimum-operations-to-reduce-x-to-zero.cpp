class Solution {
public:
    typedef long long ll;
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<ll>v(n);
 
        map<ll, ll>m;
        ll cnt = 0;
        bool flag=0;
        int i;
        int ans = INT_MAX;
        for(i=0;i<n;i++)
        {
            // cin>>v[i];
            cnt += nums[i];
            if(m[cnt]==0)
                m[cnt]=i+1;
            if(cnt==x){
                ans = min(ans, i+1);
                // cout<<ans<<" ";
                flag=1;
            }
        }
        // if(flag)
        // {
        //     cout<<"YES\n";
        //     return;
        // }
        cnt = 0;
        for(i=n-1;i>=0;i--)
        {
            cnt += nums[i];
            if(cnt==x)
            {
                ans = min(ans, n-i);
                // cout<<ans<<"k ";
                // cout<<"YES\n";return;
            }
            if(m[x-cnt]>0 and m[x-cnt] <= i)
            {
                int d = m[x-cnt];
                ans = min(ans, n-i+d);
                // cout<<ans<<"m ";
                // cout<<"YES\n";
                // return;
            }
        }
        // cout<<"NO\n";return;
        return ans==INT_MAX?-1:ans;
    }
};