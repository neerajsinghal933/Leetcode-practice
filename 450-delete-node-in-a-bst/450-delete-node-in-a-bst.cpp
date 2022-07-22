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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        if(key>root->val)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if(key<root->val)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if(!root->left and !root->right)
        {
            delete root;
            return NULL;
        }
        if(!root->left)
        {
            TreeNode* t = root->right;
            delete root;
            return t;
        }
        if(!root->right)
        {
            TreeNode* t = root->left;
            delete root;
            return t;
        }
        TreeNode* succ = root->right;
        TreeNode* par = root;
        while(succ->left)
        {
            par = succ;
            succ = succ->left;
        }
        if(par!=root)
        {
            par->left = succ->right;
        }
        else
        {
            par->right = succ->right;
        }
        root->val = succ->val;
        delete succ;
        return root;
    }
};