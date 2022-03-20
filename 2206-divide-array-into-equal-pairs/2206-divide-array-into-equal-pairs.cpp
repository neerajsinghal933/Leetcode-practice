class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // int ans = 0;
        // for(int x:nums)
        //     ans ^= x;
        // return ans==0 ? true:false;
        map<int, int>m;
        for(int x:nums)
        {
            m[x]++;
        }
        int ans = 0;
        for(auto it=m.begin(); it!=m.end(); it++)
        {
            if(it->second%2==1)
                return 0;
            // cout<<it->first<<" "<<it->second<<'\n';
        }
        // cout<<ans;
        return 1;
    }
};