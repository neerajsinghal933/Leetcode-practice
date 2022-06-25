class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        
        while(low<=high)
        {
            int mid = low + (high - low)/2;
            // cout<<mid<<" ";
            if(check(bloomDay, m, k, mid)==true)
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
    
    bool check(vector<int>&v, int m, int k, int mid)
    {
        int n = v.size();
        vector<int>temp(n);
        for(int i=0;i<n;i++)
        {
            if(v[i]<=mid)
                temp[i]=1;
            else
                temp[i]=0;
        }
        int cnt=0, curr=0;
        
        for(int i=0;i<n;i++)
        {
            if(temp[i]==1)
            {
                curr++;
            }
            else
                curr = 0;
            if(curr==k){
                cnt++;
                curr=0;
            }
        }
        // if(mid==12)
        //     cout<<cnt;
        if(cnt>=m)
            return true;
        return false;
    }
};