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
    vector<vector<string>> printTree(TreeNode* root) {
        int height = fun(root);
        int col = pow(2, height) - 1;
        // cout<<height;
        vector<vector<string>>ans(height, vector<string>(col, ""));
        fun(root, 0, col-1, 0, ans);
        return ans;
    }
    
    void fun(TreeNode* root, int i, int j, int h, vector<vector<string>>&ans)
    {
        if(!root)
            return;
        if(i>j)
            return;
        int mid = (i+j)/2;
        ans[h][mid] = to_string(root->val);
        fun(root->left, i, mid-1, h+1, ans);
        fun(root->right, mid+1, j ,h+1, ans);
    }
    
    int fun(TreeNode* root)
    {
        if(!root)
            return 0;
        return max(fun(root->left), fun(root->right)) + 1;
    }
};