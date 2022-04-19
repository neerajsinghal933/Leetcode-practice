/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*, int>m;
    vector<int>ans;
    TreeNode* init;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        init = root;
        fun(root, 0);
        countNode(root, target, k);
        return ans;
    }
    
    void fun(TreeNode* root, int cnt)
    {
        if(!root)
            return;
        m[root] = cnt;
        fun(root->left, cnt+1);
        fun(root->right, cnt+1);
    }
    
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root)
            return NULL;
        if(root==p or root==q)
            return root;
        TreeNode* l = lca(root->left, p, q);
        TreeNode* r = lca(root->right, p, q);
        if(l and r)
            return root;
        return l==NULL?r:l;
    }
    
    void countNode(TreeNode* root, TreeNode* t, int k)
    {
        if(!root)
            return;
        TreeNode* cmn = lca(init, root, t);
        if(abs(m[root] - m[cmn]) + abs(m[t] - m[cmn]) == k)
            ans.push_back(root->val);
        countNode(root->left, t, k);
        countNode(root->right, t, k);
        
    }
};