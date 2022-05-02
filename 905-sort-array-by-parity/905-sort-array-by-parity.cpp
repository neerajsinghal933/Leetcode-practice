class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), myComp);
        return nums;
    }
    
    static bool myComp(int a, int b)
    {
        return a%2 < b%2;
    }
};