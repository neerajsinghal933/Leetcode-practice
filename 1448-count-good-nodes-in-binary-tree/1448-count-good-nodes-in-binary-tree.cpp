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
    int cnt =0 ;
    int goodNodes(TreeNode* root) {
        fun(root, root->val);
        return cnt;
    }
    
    void fun(TreeNode* root, int n)
    {
        if(!root)
            return;
        if(root->val>=n)
        {
            // cout<<root->val<<" ";
            cnt++;
        }
        fun(root->left, max(root->val, n));
        fun(root->right, max(root->val, n));
    }
};