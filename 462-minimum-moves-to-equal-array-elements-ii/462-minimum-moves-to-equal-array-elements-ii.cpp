class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int first = nums[n/2];
        // int second;
        // if(n%2==0)
        //     second = nums[(n-1)/2];
        int cnt1=0;//, cnt2 =0;
        for(int i=0;i<n;i++)
        {
            cnt1 += abs(first-nums[i]);
            // if(n%2==0)
            //     cnt2 += abs(second-nums[i]);
        }
        // if(n%2)
        //     return cnt1;
        // return min(cnt1, cnt2);
        return cnt1;
    }
};