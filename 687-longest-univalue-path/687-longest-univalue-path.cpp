/**
 * Definition for a binary tree nodehttps://leetcode.com/problems/longest-univalue-path/.
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
    int ans = INT_MIN;
    int longestUnivaluePath(TreeNode* root) {
        fun(root,-1);
        return ans==INT_MIN?0:ans;
    }
    
    int fun(TreeNode* root, int t)
    {
        if(!root)
            return 0;
        int l = fun(root->left, root->val);
        int r = fun(root->right, root->val);
        
        ans = max(ans, l+r);
        if(root->val==t)
            return 1 + max(l, r);
        return 0;
    }
};