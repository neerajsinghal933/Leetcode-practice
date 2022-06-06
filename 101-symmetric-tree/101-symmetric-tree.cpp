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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return fun(root, root);
    }
    
    bool fun(TreeNode* l, TreeNode* r)
    {
        if(!l or !r)
            return !l && !r;
        if(l->val != r->val)
            return 0;
        return fun(l->left, r->right) and fun(l->right, r->left);
    }
};