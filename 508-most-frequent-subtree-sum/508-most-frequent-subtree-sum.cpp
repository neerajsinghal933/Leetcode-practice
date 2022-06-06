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
    unordered_map<int, int>m;
    int curr = INT_MIN;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        fun(root);
        vector<int>ans;
        for(auto x = m.begin(); x!=m.end(); x++)
        {
            if(x->second == curr)
                ans.push_back(x->first);
        }
        return ans;
    }
    
    int fun(TreeNode* root)
    {
        if(!root)
            return 0;
        int left = fun(root->left);
        int right = fun(root->right);
        int sum = left + right + root->val;
        m[sum]++;
        curr = max(curr, m[sum]);
        return sum;
    }
};