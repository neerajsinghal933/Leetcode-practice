class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
     map<int, int>m;
    int ans =0 ;
        for(int i=0;i<arr.size();i++)
        {
            if(m[arr[i]-d]==0)
                m[arr[i]] = 1;
            else 
            {
                m[arr[i]] = 1 + m[arr[i] - d];
                
            }
            ans = max(ans, m[arr[i]]);
                
        }
        return ans;
    }
};