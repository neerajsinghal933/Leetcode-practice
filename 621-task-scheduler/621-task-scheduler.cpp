class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int>m;
        for(char c:tasks)
            m[c]++;
        int p = tasks.size();
        priority_queue<int>pq;
        for(auto x:m)
            pq.push(x.second);
        int t = pq.top();
        pq.pop();
        int curr = (t-1)*n;
        while(!pq.empty())
        {
            curr -= min(pq.top(), t-1);
            pq.pop();
            if(curr<0)
                break;
        }
        return curr>0?p+curr:p;
    }
};