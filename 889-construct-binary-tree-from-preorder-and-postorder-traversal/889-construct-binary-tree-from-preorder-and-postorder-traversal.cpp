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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return solve(preorder, postorder, 0, n-1, 0, n-1);
    }
    
    TreeNode* solve(vector<int>&pre, vector<int>&post, int pres, int pree, int posts, int poste)
    {
        if(pres>pree or posts>poste)
            return NULL;
        TreeNode* root = new TreeNode(pre[pres]);
        if(pree==pres or poste==posts)
            return root;
        int i;
        for(i=0;i<post.size();i++)
        {
            if(post[i]==pre[pres+1])
                break;
        }
        root->left = solve(pre, post, pres+1, pres+i+1-posts, posts, i);
        root->right = solve(pre, post, pres+i+2-posts, pree, i+1, poste-1);
        return root;
    }
};