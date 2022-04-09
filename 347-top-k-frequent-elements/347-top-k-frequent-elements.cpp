class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        
        priority_queue<pair<int, int>>q;
        
        for(auto it = m.begin(); it!=m.end(); it++)
        {
            q.push({it->second, it->first});
        }
        
        vector<int>res;
        while(k--)
        {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};