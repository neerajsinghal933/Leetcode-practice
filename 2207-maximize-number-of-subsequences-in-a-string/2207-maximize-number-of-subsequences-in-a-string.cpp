class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long ans = 0;
        long long cnt1 = 0, cnt2=0;
        for(char c:text)
        {
             
            if(c==pattern[1])
            {
                cnt2++;
                ans += cnt1;
            }
            if(c==pattern[0])
                cnt1++;
            
        }
        return ans + max(cnt1, cnt2);
    }
};