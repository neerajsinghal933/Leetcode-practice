class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        deque<int>q;
        q.push_back(0);
        
        
        for(int i=1;i<n;i++)
        {
            if(i-q.front()>k)
                q.pop_front();
            int val = nums[q.front()] + nums[i];
            
            nums[i] = val;
            while(!q.empty() and val>nums[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        return nums[q.back()];
    }
};