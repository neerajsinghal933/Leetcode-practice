class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map<int, int>m;
        int i, num;
        for(i=0;i<n;i++)
        {
            vector<int>g(cells.begin(), cells.end());
            num = 0;
            for(int j=0;j<8;j++)
            {
                if(j==0 or j==7)
                    g[j] = 0;
                else if(cells[j-1]==cells[j+1])
                    g[j] = 1;
                else
                    g[j] = 0;
                num += (g[j]<<j);
            }
            if(m.find(num)!=m.end())
                break;
            else
                m[num] = i;
            cells = g;
        }
        if(i==n)
            return cells;
        int k = m[num];
        int cnt = i-k;
        int require = (n-k)%cnt;
        
        for(i=0;i<require;i++)
        {
            vector<int>g(cells.begin(), cells.end());
            // num = 0;
            for(int j=0;j<8;j++)
            {
                if(j==0 or j==7)
                    g[j] = 0;
                else if(cells[j-1]==cells[j+1])
                    g[j] = 1;
                else
                    g[j] = 0;
                // num += g[j]<<i;
            }
            // if(m.find(num)!=m.end())
            //     break;
            // else
            //     m[num] = i;
            cells = g;
        }
            
        return cells;
    }
};