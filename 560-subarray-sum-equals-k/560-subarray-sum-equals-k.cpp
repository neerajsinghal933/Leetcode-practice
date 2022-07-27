class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        int sum = 0;
        int cnt =0 ;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            if(sum==k)
                cnt++;
            if(m[sum-k])
                cnt += m[sum-k];
            m[sum]++;
        }
        return cnt;
    }
};