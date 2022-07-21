/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return fun(nums, 0, n-1);
    }
    
    TreeNode* fun(vector<int>&nums, int i, int j)
    {
        if(i>j)
            return NULL;
        int mid = (i+j)/2;
        TreeNode* t = new TreeNode(nums[mid]);
        t->left = fun(nums, i, mid-1);
        t->right = fun(nums, mid+1, j);
        return t;
    }
};