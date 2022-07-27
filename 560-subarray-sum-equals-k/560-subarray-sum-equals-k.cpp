class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        m[nums[0]]++;
        int cnt = 0;
        if(k==nums[0])
            cnt++;
        int n = nums.size();
        for(int i=1;i<n;i++)
        {
            nums[i] += nums[i-1];
            if(nums[i]==k)
                cnt++;
            if(m[nums[i]-k])
                cnt += m[nums[i]-k];
            m[nums[i]]++;
        }
        return cnt;
    }
};