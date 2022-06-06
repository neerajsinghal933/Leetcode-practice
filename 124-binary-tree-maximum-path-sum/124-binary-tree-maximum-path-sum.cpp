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
    
    int fun(TreeNode* root, int &sum)
    {
        if(!root)
            return 0;
        int left = fun(root->left, sum);
        int right = fun(root->right, sum);
        
        int first = max(max(left, right) + root->val, root->val);
        int second = max(first, left + right + root->val);
        sum = max(sum, second);
        // ans = max(ans, sum);
        return first;
    }
};