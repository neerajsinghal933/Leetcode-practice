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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        pair<int, int>a, b;
        while(!q.empty())
        {
            TreeNode* t = q.front().first;
            int h = q.front().second;
            q.pop();
            if(t->left)
            {
                q.push({t->left, h+1});
                if(t->left->val==x)
                    a = {h+1, t->val};
                if(t->left->val==y)
                    b = {h+1, t->val};
            }
            if(t->right)
            {
                q.push({t->right, h+1});
                if(t->right->val==x)
                    a = {h+1, t->val};
                if(t->right->val==y)
                    b = {h+1, t->val};
            }
        }
        cout<<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second;
        return a.first==b.first and a.second!=b.second;
    }
};