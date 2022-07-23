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
    TreeNode* fun(vector<int>&v, int s, int e)
    {
        if(s>e)
            return NULL;
        TreeNode* root = new TreeNode(v[s]);
        int i;
        for(i=s;i<=e;i++)
        {
            if(v[i]>v[s])
                break;
        }
        root->left = fun(v, s+1, i-1);
        root->right = fun(v, i, e);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return fun(preorder, 0, n-1);
    }
};