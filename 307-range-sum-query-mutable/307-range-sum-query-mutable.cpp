struct segTree{
    int start, end, sum;
    segTree* left;
    segTree* right;
    segTree(int a, int b)
    {
        start = a;
        end = b;
        sum = 0;
        left = NULL;
        right = NULL;
    }
};

class NumArray {
    segTree* root;
public:
    
    NumArray(vector<int>& nums) {
        int n = nums.size();
        root = build(0, n-1, nums);
        
    }
    
    void update(int index, int val) {
        modify(index, val, root);
    }
    
    int sumRange(int left, int right) {
        return query(left, right, root);
    }
    
    segTree* build(int s, int e, vector<int>&nums)
    {
        if(s>e)
            return NULL;
        segTree* root = new segTree(s, e);
        if(s==e)
        {
            root->sum = nums[s];
            return root;
        }
        int mid = (s+e)/2;
        root->left = build(s, mid, nums);
        root->right = build(mid+1, e, nums);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }
    
    int modify(int i, int val, segTree* root)
    {
        if(!root)
            return 0;
        int diff;
        if(root->start == i and root->end == i)
        {
            diff = val - root->sum;
            root->sum = val;
            return diff;
        }
        int mid = (root->start + root->end)/2;
        if(i>mid)
        {
            diff = modify(i, val, root->right);
        }
        else
            diff = modify(i, val, root->left);
        root->sum = root->sum + diff;
        return diff;
    }
    
    int query(int l, int r, segTree* root)
    {
        if(!root)
            return 0;
        if(root->start == l and root->end == r)
            return root->sum;
        int mid = (root->start + root->end)/2;
        if(l>mid)
            return query(l, r, root->right);
        if(r<=mid)
            return query(l, r, root->left);
        return query(l, mid, root->left) + query(mid+1, r, root->right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */