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
        
        return fun(root->left, root->right);// and isSymmetric(root->left) and isSymmetric(root->right) ;
    }
    
    bool fun(TreeNode* root1, TreeNode* root2)
    {
        if(!root1 or !root2)
        {
            if(!root1 and !root2)
                return true;
            return false;
        }
            // return true
        return root1->val == root2->val and fun(root1->left, root2->right) and fun(root1->right, root2->left);
    }
};