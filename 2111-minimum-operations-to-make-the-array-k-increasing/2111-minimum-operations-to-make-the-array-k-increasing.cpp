class Solution {
public:
    
    int fun(vector<int>&v)
    {
        int n = v.size();
        vector<int>t(n+1, INT_MAX);
        t[0] = INT_MIN;
        int ans =0 ;
        for(int i=0;i<n;i++)
        {
            // if(t.back()<=v[i])
            //     t.push_back(v[i]);
            int it = upper_bound(t.begin(), t.end(), v[i]) - t.begin() ;
            ans = max(ans, it);
            t[it] = v[i];
        }
        return n-ans;
    }
    
    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        if(n<=k)
            return 0;
        // if(k==1)
            
        int ans = 0;
        for(int i=0;i<k;i++)
        {
            vector<int>t;
            for(int j=i;j<n;j+=k)
                t.push_back(arr[j]);
            ans += fun(t);
        }
        return ans;
    }
};