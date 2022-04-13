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
    
    int fun(TreeNode* root, int& result)
    {
        if(!root)
            return 0;
        int left = fun(root->left, result);
        int right = fun(root->right, result);
        
        int st = max(max(left, right) + root->val, root->val);
        int se = max(left+right+root->val, st);
        result = max(result, se);
        return st;
    }
    
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        fun(root, result);
        return result;
    }
};