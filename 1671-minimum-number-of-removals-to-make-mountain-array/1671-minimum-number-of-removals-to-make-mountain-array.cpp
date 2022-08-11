class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
	    vector<int>lis(n, 1), lds(n, 1);
	    for(int i=0;i<n;i++)
	    {
	        for(int j=i;j>=0;j--)
	        {
	            if(nums[i]>nums[j])
	                lis[i] = max(lis[i], lis[j]+1);
	        }
	    }
	    for(int i=n-1;i>=0;i--)
	    {
	        for(int j=i;j<n;j++)
	        {
	            if(nums[i]>nums[j])
	                lds[i] = max(lds[i], lds[j]+1);
	        }
	    }
	    int mx = 0;
	    for(int i=0;i<n;i++)
            if(lis[i]!=1 and lds[i]!=1)
	            mx = max(mx, lds[i]+lis[i]-1);
	       // return mx;
        return n - mx;
    }
};