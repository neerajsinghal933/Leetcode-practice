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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>ans;
        TreeNode* curr = root;
        while(curr!=NULL or !st.empty())
        {
            while(curr!=NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            TreeNode* t = st.top();
            st.pop();
            ans.push_back(t->val);
            curr = t->right;
        }
        return ans;
    }
};