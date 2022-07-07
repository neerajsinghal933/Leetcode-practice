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
    void inorder(TreeNode* root, vector<int>&v)
    {
        if(!root)
            return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }
    
    TreeNode* fun(vector<int>&v, int i, int j)
    {
        if(i>j)
            return NULL;
        int mid = i + (j-i)/2;
        TreeNode* t = new TreeNode(v[mid]);
        t->left = fun(v, i, mid-1);
        t->right = fun(v, mid+1, j);
        return t;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        inorder(root, v);
        root = fun(v, 0, v.size()-1);
        return root;
    }
};