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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
    
    void fun(TreeNode* root)
    {
        if(!root )
            return;
        fun(root->left);
        if(first == NULL and root->val < prev->val)
            first = prev;
        if(first!=NULL and root->val < prev->val)
            second = root;
        prev = root;
        fun(root->right);
    }
    
    
    void recoverTree(TreeNode* root) {
        fun(root);
        swap(first->val, second->val);
    }
};