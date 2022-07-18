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
    unordered_map<int, int>m;
    vector<TreeNode*>ans;
    
    TreeNode* fun(TreeNode* root)
    {
        if(!root)
            return NULL;
        TreeNode* left = fun(root->left);
        TreeNode* right = fun(root->right);
        root->left = left;
        root->right = right;
        if(m[root->val]==1)
        {
            if(root->left)
                ans.push_back(root->left);
            if(root->right)
                ans.push_back(root->right);
            m[root->val]=0;
            return NULL;
        }
        return root;
        // fun(root->left);
        // fun(root->right);
    }
    
//     void solve(TreeNode* root)
//     {
//         if(!root)
//             return;
//         if(root->val == -1 and root->left and root->left->val != -1)
//             ans.push_back(root->left);
        
//         if(root->val == -1 and root->right and root->right->val != -1)
//             ans.push_back(root->left);
//         solve(root->left);
//         solve(root->right);
//         root = NULL;
//     }
    
    // void print(TreeNode* root)
    // {
    //     if(!root)
    //         return;
    //     print(root->left);
    //     cout<<root->val<< " ";
    //     print(root->right);
    // }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int x:to_delete)
            m[x]++;
        root = fun(root);
        if(root)
            ans.push_back(root);
        // print(root);
        // solve(root);
        return ans;
    }
    
    
};