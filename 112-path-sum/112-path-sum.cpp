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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return fun(root, targetSum);
    }
    
    bool fun(TreeNode* root, int t)
    {
        if(!root)
            return 0;
        if(!root->left and !root->right and t-root->val==0)
            return true;
        return fun(root->left, t - root->val) or fun(root->right, t - root->val);
    }
};