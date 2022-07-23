class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>>v;
        for(int i=0;i<n;i++)
            v.push_back({nums[i], i});
        vector<int>cnt(n, 0);
        mergeSort(nums, 0, n-1, v, cnt);
        return cnt;
    }
        
        
    void mergeSort(vector<int>&nums, int l, int h, vector<pair<int, int>>&v, vector<int>&cnt)
    {
        if(l>=h)
            return;
        int mid = (l+h)/2;
        mergeSort(nums, l, mid, v, cnt);
        mergeSort(nums, mid+1, h, v, cnt);
        merge(nums, l, mid, h, v, cnt);
    }

    void merge(vector<int>&nums, int l, int mid, int h, vector<pair<int, int>>&v, vector<int>&cnt)
    {
        vector<pair<int, int>>temp(h-l+1);
        int i=l;
        int j = mid+1;
        int k=0;
        while(i<=mid and j<=h)
        {
            if(v[i].first<=v[j].first)
            {
                temp[k++] = v[j++];
            }
            else
            {
                cnt[v[i].second] += h-j+1;
                temp[k++] = v[i++];
            }
        }
        while(i<=mid)
        {
            temp[k++] = v[i++];
        }
        while(j<=h)
        {
            temp[k++] = v[j++];
        }
        for(int i=l;i<=h;i++)
        {
            v[i] = temp[i-l];
        }
    }
    
};