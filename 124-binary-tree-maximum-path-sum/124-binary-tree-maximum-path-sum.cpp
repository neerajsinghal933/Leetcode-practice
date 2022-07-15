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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        fun(root, ans);
        return ans;
    }
    
    int fun(TreeNode* root, int &ans)
    {
        if(!root)
            return 0;
        int left = fun(root->left, ans);
        int right = fun(root->right, ans);
        int first = max(left + right + root->val, root->val);
        int second = max(first, max(left, right) + root->val);
        ans = max(ans, second);
        return max(max(left, right) + root->val, root->val);
        
    }
};