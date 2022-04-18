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
    int res = -1;
    void fun(TreeNode* root, int &k)
    {
        if(root==NULL)
            return ;
        // TreeNode* l = fun(root->left, k);
        // if(l != NULL)
        //     return l;
        // k--;
        // if(k==0)
        //     return root;
        // return fun(root->right, k);
        
        fun(root->left, k);
        k--;
        if(k==0)
        {
            res = root->val;return;
        }
        fun(root->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        // TreeNode* temp = fun(root, k);
        // if(temp)
        //     return temp->val;
        // return -1;
        fun(root, k);
        return res;
    }
};