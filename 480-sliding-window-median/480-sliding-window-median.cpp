class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        bool odd = k%2;
        vector<double>ans;
         multiset<int>st;
        for(int i=0;i+k<=n;i++)
        {
           
            if(i==0)
            {
                for(int j=0;j<k;j++)
                {
                    st.insert(nums[j]);
                }
                if(odd)
                {
                    auto it = next(st.begin(), k/2);
                    ans.push_back(*it);
                }
                else
                {
                    auto it1 = next(st.begin(), k/2-1);
                    auto it2 = next(st.begin(), k/2);
                    ans.push_back((double)(*it1)/2.0 + (double)(*it2)/2.0);
                }
            }
            else
            {
                if(nums[i-1]!=nums[i+k-1])
                {
                    st.erase(st.find(nums[i-1]));
                    st.insert(nums[i+k-1]);
                    if(odd)
                    {
                        auto it = next(st.begin(), k/2);
                        ans.push_back(*it);
                    }
                    else
                    {
                        auto it1 = next(st.begin(), k/2-1);
                        auto it2 = next(st.begin(), k/2);
                        ans.push_back((double)(*it1)/2.0 + (double)(*it2)/2.0);
                    }
                }
                else
                {
                    ans.push_back(ans.back());
                }
            }
        }
        return ans;
    }
};