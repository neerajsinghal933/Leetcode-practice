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
        if(key > root->val)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        if(key < root->val)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        if(!root->left and !root->right)
        {
            delete root;
            return NULL;
        }
        if(!root->right)
        {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        if(!root->left)
        {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }
        TreeNode* succ = root->left;
        TreeNode* par = root;
        while(succ->right != NULL)
        {
            par = succ;
            succ = succ->right;
        }
        if(root!=par)
        {
            par->right = succ->left;
        }
        else
        {
            par->left = succ->left;
        }
        root->val = succ->val;
        delete succ;
        return root;
    }
};