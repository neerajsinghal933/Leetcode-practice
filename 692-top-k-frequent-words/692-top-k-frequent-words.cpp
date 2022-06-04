class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int>m;
        for(string s:words)
            m[s]++;
        priority_queue<pair<int, string>>pq;
        for(auto it=m.begin();it!=m.end();it++)
        {
            pq.push({it->second, it->first});
        }
        vector<pair<string, int>>v;
        while(!pq.empty())
        {
            v.push_back({pq.top().second, pq.top().first});
            pq.pop();
        }
        sort(v.begin(), v.end(), myComp);
        vector<string>ans;
        for(int i=0;i<k;i++)
            ans.push_back(v[i].first);
        return ans;
    }
    
    static bool myComp(pair<string, int>p1, pair<string, int>p2)
    {
        if(p1.second==p2.second)
            return p1.first<p2.first;
        return p1.second > p2.second;
    }
};