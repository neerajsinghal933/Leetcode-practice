class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int>freq(26, 0);
        
        for(char c:s)
        {
            int mx = 0;
            
            for(int i=c-k;i<=c+k;i++)
            {
                // cout<<i<< " ";
                int k = i - 'a';
                // cout<<k<<" ";
                // i = i - 'a';
                if(k>=0 and k<26)
                    mx = max(mx, freq[k]);
            }
            freq[c-'a'] = mx+1;
        }
        return *max_element(freq.begin(), freq.end());
    }
};