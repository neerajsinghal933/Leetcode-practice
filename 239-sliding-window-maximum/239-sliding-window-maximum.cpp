class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0, j=0;
        deque<int>q;
        vector<int>ans;
        int n = nums.size();
        
        while(j<n)
        {
            if(q.empty())
                q.push_back(nums[j]);
            else
            {
                while(!q.empty() and q.back()<nums[j])
                {
                    q.pop_back();
                }
                q.push_back(nums[j]);
            }
            
            if(j-i+1<k)
                j++;
            else
            {
                ans.push_back(q.front());
                if(q.front()==nums[i])
                    q.pop_front();
                i++;
                j++;
            }
        }
        return ans;
    }
};