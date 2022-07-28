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
    map<int, int>mp;
    
    void fun(TreeNode* root, int h)
    {
        if(!root)
            return;
        mp[root->val] = h;
        fun(root->left, h+1);
        fun(root->right, h+1);
    }
    
    TreeNode* lca(TreeNode* root, int n1, int n2)
    {
        if(!root)
            return NULL;
        if(root->val == n1 or root->val == n2)
            return root;
        TreeNode* l = lca(root->left, n1, n2);
        TreeNode* r = lca(root->right, n1, n2);
        if(l and r)
            return root;
        return l==NULL?r:l;
    }
    
    bool recur(TreeNode* root, int n1, int n2, string &s)
    {
        if(!root)
            return false;
        if(root->val==n2)
            return true;
        s += "L";
        if(recur(root->left, n1, n2, s))
            return true;
        s.pop_back();
        s += "R";
        if(recur(root->right, n1, n2, s))
            return true;
        s.pop_back();
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        fun(root, 0);
        TreeNode* cmn = lca(root, startValue, destValue);
        // cout<<cmn->val;
        string ans = "";
        int h1 = mp[startValue];
        int h2 = mp[destValue];
        int height = mp[cmn->val];
        int d = h1 - height;
        while(d>0){
            ans += "U";
            d--;
        }
        if(recur(cmn, startValue, destValue, ans))
        return ans;
        return "";
    }
};