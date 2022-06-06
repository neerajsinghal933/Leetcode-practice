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
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)
            return NULL;
        if(fun(root))
            return root;
        return NULL;
    }
    
    bool fun(TreeNode* root)
    {
        if(!root)
            return true;
        
        if(!fun(root->left))
            root->left = NULL;
        if(!fun(root->right))
            root->right = NULL;
        if(!root->left and !root->right and root->val==0)
            return 0;
        return true;
    }
    
    
};