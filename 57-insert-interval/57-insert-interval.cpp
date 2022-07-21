class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& newInterval) {
        // v.push_back(newInterval);
        int n = v.size();
        vector<vector<int>>res;
        if(n==0)
        {
            res.push_back(newInterval);
            return res;
        }
        // sort(v.begin(), v.end());
        
        int pos = -1;
        int val = newInterval[0];
        int l = 0, h = n-1;
        while(l<=h)
        {
            int mid = (l+h)/2;
            if(v[mid][0]<=val)
            {
                pos = mid;
                l = mid+1;
            }
            else
                h = mid-1;
        }
        // cout<<pos+1;
        // v.insert(pos+1, newInterval);
        v.insert(v.begin() + pos + 1, newInterval);
        
        // for(auto x:v)
        // {
        //     cout<<x[0]<<" "<<x[1]<<endl;
        // }
        
        
        
        int a = v[0][0];
        int b = v[0][1];
        
        int i;
        for(i=1;i<=n;i++)
        {
            if(v[i][0]<=b)
                b = max(b, v[i][1]);
            else
            {
                res.push_back({a, b});
                a = v[i][0];
                b = v[i][1];
            }
            
        }
            
        res.push_back({a, b});
        return res;
    }
};