class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        // map<pair<int, int>, int>m;
        set<pair<int, int>>v;
        unordered_map<int, int>row;
        unordered_map<int, int>col;
        unordered_map<int, int>di;
        unordered_map<int, int>dil;
        for(auto x:lamps)
        {
            if(v.find({x[0], x[1]})==v.end())
            {
                row[x[0]]++;
                col[x[1]]++;
                di[x[0]+x[1]]++;
                dil[x[0]-x[1]]++;
                v.insert({x[0], x[1]});
            }
        }
        vector<pair<int, int>>dir = {{1, 0}, {1, 1}, {1, -1}, {0, 1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
        vector<int>ans;
        // set<pair<int, int>>st;
        for(auto a:queries)
        {
            int x = a[0];
            int y = a[1];
            // int flag = true;
            // if(st.find({x, y}) != st.end())
            // {
            //     flag = false;
            //     cout<<"yeppp";
            // }
            if(row[x]>0 or col[y]>0 or di[x+y]>0 or dil[x-y]>0)
            {
                // cout<<"hu\n";
                ans.push_back(1);
            
                // st.insert({x, y});
                 auto it = v.find({x, y});
                if(it!=v.end())
                {
                    row[x]--;
                    col[y]--;
                    di[x+y]--;
                    dil[x-y]--;
                    v.erase({x, y});
                }
                for(int i=0;i<8;i++)
                {
                    int cx = x + dir[i].first;
                    int cy = y + dir[i].second;
                    if(cx<0 or cx>=n or cy<0 or cy>=n)
                        continue;
                    auto it = v.find({cx, cy});
                    if(it!=v.end())
                    {
                        row[cx]--;
                        col[cy]--;
                        di[cx+cy]--;
                        dil[cx-cy]--;
                        v.erase({cx, cy});
                    }
                }
            }
            else
            {
                ans.push_back(0);
                // continue;
            }
                
            // cout<<"JIIIIIIIIIII\n";
            
        }
        // for(auto &it:v)
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        // if(st.find({1, 0}) != st.end())
        //     cout<<"eys";
        return ans;
    }
};