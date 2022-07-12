class Solution {
public:
    map<int, vector<int>>m;
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
            m[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        int sz = m[target].size();
        int n = rand()%sz;
        return m[target][n];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */