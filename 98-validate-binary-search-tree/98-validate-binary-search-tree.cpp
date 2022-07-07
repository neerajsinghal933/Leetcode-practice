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
    bool isValidBST(TreeNode* root) {
        return fun(root, LONG_MIN, LONG_MAX);
    }
    
    bool fun(TreeNode* root, long mn, long mx)
    {
        if(!root)
            return true;
        if(root->val <= mn or root->val >= mx)
            return false;
        return fun(root->left, mn, root->val) and fun(root->right, root->val, mx);
    }
};