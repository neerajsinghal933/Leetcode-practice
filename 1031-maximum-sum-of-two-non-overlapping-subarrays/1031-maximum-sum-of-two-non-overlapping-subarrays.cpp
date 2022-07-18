class Solution {
public:
    int fun(vector<int>&nums, int s, int e, int len)
    {
        int sum = 0, mx=0;
        int i=s, j =  s;
        while(i<=e)
        {
            int sz = i - j +1;
            sum += nums[i];
            if(sz > len)
            {
                sz--;
                sum -= nums[j];
                j++;
            }
            if(sz==len)
                mx = max(mx, sum);
            i++;
        }
        return mx;
    }
    
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0, mx = 0;
        while(i<n)
        {
            sum += nums[i];
            int len = i - j +1;
            if(len > firstLen)
            {
                len--;
                sum -= nums[j];
                j++;
            }
            int curr = 0;
            if(len == firstLen)
            {
                int n1 = fun(nums, 0, j-1, secondLen);
                int n2 = fun(nums, i+1, n-1, secondLen);
                curr = max(n1, n2);
            }
            mx = max(mx, curr+sum);
            i++;
        }
        
        return mx;
            
    }
};