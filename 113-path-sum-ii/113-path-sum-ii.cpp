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
    void fun(TreeNode* root, int t, vector<int>&arr, vector<vector<int>>&res)
    {
        if(!root)
            return;
        
        t -= root->val;
        arr.push_back(root->val);
        
        if(t==0 && !root->left && !root->right)
            res.push_back(arr);
        
        fun(root->left, t, arr, res);
        fun(root->right, t, arr, res);
        arr.pop_back();
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        
        if(!root)
            return res;
        vector<int>temp;
        fun(root, targetSum, temp, res);
        return res;
    }
};