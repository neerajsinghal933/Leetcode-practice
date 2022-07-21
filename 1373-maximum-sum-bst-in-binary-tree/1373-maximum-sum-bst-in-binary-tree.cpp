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
    int ans = 0;
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
    
    void solve(TreeNode* root)
    {
        if(!root)
            return;
        int sum = 0;
        if(check(root, INT_MIN, INT_MAX)==true)
        {
            get_sum(root, sum);
            ans = max(ans, sum);
            return;
        }
        solve(root->left);
        solve(root->right);
    }
    
    bool check(TreeNode* root, int a, int b)
    {
        if(!root)
            return true;
        if(root->val <= a or root->val >= b)
            return false;
        return check(root->left, a, root->val) and check(root->right, root->val, b);
    }
    
    int get_sum(TreeNode* root, int &sum)
    {
        if(!root)
            return 0;
        int x = get_sum(root->left, sum) + get_sum(root->right, sum) + root->val;
        sum = max(x, sum);
        return x;
    }
};