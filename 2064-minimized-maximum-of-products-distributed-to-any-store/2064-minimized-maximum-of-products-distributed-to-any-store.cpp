class Solution {
public:
    int minimizedMaximum(int n, vector<int>& v) {
        int l = 1;
        int h = *max_element(v.begin(), v.end());
        int ans=0;
        while(l<=h)
        {
            int mid = (l+h)/2;
            if(fun(mid, v) <= n)
            {
                ans = mid;
                h = mid-1;
            }
            else
                l = mid+1;
        }
        return ans;
    }
    
    int fun(int mid, vector<int>&v)
    {
        int ans = 0;
        for(int x:v)
        {
            ans += x/mid;
            if(x%mid>0)
                ans+=1;
        }
        return ans;
        
    }
};