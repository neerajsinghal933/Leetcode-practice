class Solution {
public:
    string reorganizeString(string s) {
        map<char, int>m;
        for(char c:s)
            m[c]++;
        priority_queue<pair<int, char>>pq;
        for(auto x:m)
        {
            pq.push({x.second, x.first});
        }
        int n = s.size();
        int i=0;
        char c = pq.top().second;
        int cnt = pq.top().first;
        
        if(cnt > (n+1)/2)
            return "";
        
        pq.pop();
        while(cnt)
        {
            s[i] = c;
            i+=2;
            cnt--;
        }
        
        while(pq.size())
        {
            c = pq.top().second;
            cnt = pq.top().first;
            pq.pop();
            while(cnt)
            {
                if(i>=n)
                    i=1;
                s[i]=c;
                cnt--;
                i+=2;
            }
        }
        return s;
    }
};