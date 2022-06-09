class Solution {
public:
    typedef long long ll;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for(int i=0;i<tasks.size();i++)
            tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());   
        ll t = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>pq;
        vector<int>ans;
        // ans.push_back(tasks[0][2]);
        // t = tasks[0][1] + 1;
        ll i=0;
        while(!pq.empty() or i<n)
        {
           if(pq.empty())
           {
               t = tasks[i][0];
           }
            else
            {
                pair<int, int>a = pq.top();
                pq.pop();
                t += a.first;
                ans.push_back(a.second);
            }
            while(i<n and tasks[i][0]<=t)
            {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
        }
        return ans;
    }
    
    
    
    
    // static bool comp(vector<int>&a, vector<int>&b)
    // {
    //     if(a[0]==b[0])
    //         return a[1]<b[1];
    //     return a[0]<b[0];
    // }
};