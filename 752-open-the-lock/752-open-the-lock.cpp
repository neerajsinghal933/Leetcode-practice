class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string>q;
        int cnt = -1;
        q.push("0000");
        if(find(deadends.begin(), deadends.end(), "0000")!=deadends.end())
            return -1;
        map<string, int>mp;
        vector<vector<int>>dir  = {{0, 1}, {0, -1}, {1, 1}, {1, -1}, {2, 1}, {2, -1}, {3, 1}, {3, -1}};
        while(!q.empty())
        {
            cnt++;
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                string s = q.front();
                q.pop();
                if(s==target)
                    return cnt;
                for(int k=0;k<8;k++)
                {
                    string t = s;
                    t[dir[k][0]] = (t[dir[k][0]] - '0' + dir[k][1]+10)%10 + '0'; 
                    // cout<<t<<" ";
                    // break;
                    if(mp[t]==1)
                        continue;
                    mp[t] = 1;
                    if(find(deadends.begin(), deadends.end(), t)==deadends.end())
                    {
                        q.push(t);
                    }
                }
                // break;
            }
            // break;
        }
        return -1;
    }
};