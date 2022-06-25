class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        int mn = INT_MIN;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<=nums[i+1])
             mn = nums[i];
            else
            {
                if(nums[i+1]<mn)
                {
                    nums[i+1] = nums[i];
                    
                }
                cnt++;
            }
            if(cnt>1)
                return false;
        }
        return true;
    }
};