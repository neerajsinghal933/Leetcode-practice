class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = 1e9+7;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<int, long>m;
        m[arr[0]] = 1;
        for(int i=1;i<n;i++)
        {
            long cnt = 1;
            for(auto x:m)
            {
                int ele = x.first;
                if(arr[i]%ele==0 and m.find(arr[i]/ele)!=m.end())
                {
                    cnt += m[arr[i]/ele] * m[ele];
                }
            }
            m[arr[i]] = cnt;
        }
        int ans = 0;
        for(auto x:m)
            ans =(ans + x.second)%mod;
        return ans;
    }
};