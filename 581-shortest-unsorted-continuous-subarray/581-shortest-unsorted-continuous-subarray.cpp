class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>v(nums.begin(), nums.end());
        sort(v.begin(), v.end());
        
        int cnt = 0;
        int i;
        int n = nums.size();
        for(i=0;i<n;i++)
        {
            if(nums[i]!=v[i])
                break;
        }
        
        for(int j=n-1;j>=0, j>=i;j--)
        {
            if(nums[j]==v[j])
                cnt++;
            else
                break;
        }
        // cout<<i<<" "<<cnt;
        return n-cnt-i;
        
    }
};