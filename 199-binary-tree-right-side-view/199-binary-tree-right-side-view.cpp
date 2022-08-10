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
    
    // unordered_map<int, int>m;
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        fun(root, 0, res);
        return res;
    }
    
    void fun(TreeNode* root, int curr, vector<int>&res)
    {
        if(!root)
            return;
        if(res.size()==curr){
            // m[curr] = 1;
            res.push_back(root->val);
        }
        fun(root->right, curr+1, res);
        fun(root->left, curr+1, res);
    }
};