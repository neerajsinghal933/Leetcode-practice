class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            sum %= k;
            if(sum==0 and i>0)
                return true;
            if(m.find(sum)!=m.end())
            {
                if(i-m[sum]>1)
                    return true;
            }
            else
            m[sum] = i;
        }
        return false;
    }
};