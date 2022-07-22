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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* t = st.top();
            st.pop();
            if(t->right)
                st.push(t->right);
            if(t->left)
                st.push(t->left);
            if(!st.empty())
                t->right = st.top();
            t->left = NULL;
        }
    }
};