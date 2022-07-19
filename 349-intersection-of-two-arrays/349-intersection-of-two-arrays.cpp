class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int>m;
        for(int x:nums1)
            m[x]=1;
        for(int x:nums2)
        {
            if(m[x]==1)
                m[x]=2;
        }
        vector<int>ans;
        for(auto x:m)
            if(x.second==2)
                ans.push_back(x.first);
        return ans;
    }
};