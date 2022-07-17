class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        int i, j;
        for(i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
                break;
        }
        if(i<0)
            reverse(nums.begin(), nums.end());
        else
        {
            for(j=n-1;j>i;j--)
            {
                if(nums[j]>nums[i])
                    break;
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};

// 1 2 3
    
//     3 2 1
//     1 2  3
    
//     1 2 4 5 4 3 2
//     1 2 5 4 4 3 2
    
//     1 2 5 2 3 4 4
    
//     1 2 5 2 3 4 4