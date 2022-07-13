class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int n = queens.size();
        int x = king[0];
        int y = king[1];
        map<pair<int, int>, int>m;
        for(auto x:queens)
            m[{x[0], x[1]}]++;
        vector<vector<int>>ans;
        for(int i=x+1;i<8;i++)
        {
            if(m[{i, y}])
            {
                ans.push_back({i, y});
                break;
            }
        }
        for(int i=x-1;i>=0;i--)
        {
            if(m[{i, y}])
            {
                ans.push_back({i, y});
                break;
            }
        }
        for(int i=y+1;i<8;i++)
        {
            if(m[{x, i}])
            {
                ans.push_back({x, i});
                break;
            }
        }
        for(int i=y-1;i>=0;i--)
        {
            if(m[{x, i}])
            {
                ans.push_back({x, i});
                break;
            }
        }
        for(int i=x+1, j=y+1; i<8, j<8; i++, j++)
        {
            if(m[{i, j}])
            {
                ans.push_back({i, j});
                break;
            }
        }
        for(int i=x+1, j=y-1; i<8, j>=0; i++, j--)
        {
            if(m[{i, j}])
            {
                ans.push_back({i, j});
                break;
            }
        }
        for(int i=x-1, j=y+1; i>=0, j<8; i--, j++)
        {
            if(m[{i, j}])
            {
                ans.push_back({i, j});
                break;
            }
        }
        for(int i=x-1, j=y-1; i>=0, j>=0; i--, j--)
        {
            if(m[{i, j}])
            {
                ans.push_back({i, j});
                break;
            }
        }
        return ans;
    }
};