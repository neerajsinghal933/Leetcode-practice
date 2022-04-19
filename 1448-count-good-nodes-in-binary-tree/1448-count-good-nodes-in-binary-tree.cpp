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
    int cnt = 0;
    int goodNodes(TreeNode* root) {
        
        fun(root, root->val);
        return cnt;
    }
    
    void fun(TreeNode* root, int v)
    {
        if(!root)
            return ;
        if(root->val >= v){
            cnt++;
            cout<<root->val<<" ";
        }
        fun(root->left, max(v, root->val));
        fun(root->right, max(v, root->val));
    }
};