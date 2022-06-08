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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>res;
        unordered_map<string, int>m;
        fun(root, res, m);
        return res;
    }

    string fun(TreeNode* root, vector<TreeNode*>&res, unordered_map<string, int>&m)
    {
        if(!root)
            return "";
        string s = to_string(root->val) + "r" + fun(root->right, res, m) + "l" + fun(root->left, res, m);
        m[s]++;
        if(m[s]==2)
            res.push_back(root);
        return s;
        
    }
};