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
    int k=0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return fun(preorder, inorder, 0, inorder.size()-1);
    }
    
    
    TreeNode* fun(vector<int>& preorder, vector<int>& inorder, int s, int e)
    {
        if(s>e)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[k++]);
        int idx = find(inorder, s, e, root->val);
        root->left = fun(preorder, inorder, s, idx-1);
        root->right = fun(preorder, inorder, idx+1, e);
        return root;
        
    }
    
    int find(vector<int>&in, int s, int e, int x)
    {
        for(int i=s;i<=e;i++)
        {
            if(in[i]==x)
                return i;
        }
        return -1;
    }
};