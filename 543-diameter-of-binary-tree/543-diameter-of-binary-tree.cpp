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
    int diameterOfBinaryTree(TreeNode* root) {
        return fun(root);
    }
    
    int fun(TreeNode* root)
    {
        if(!root)
            return 0;
        int h = height(root->left) + height(root->right) ;
        return max({h, fun(root->left), fun(root->right)});
    }
    
    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};