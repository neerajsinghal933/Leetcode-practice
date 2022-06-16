class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int>m;
        for(char c:s)
            m[c]++;
        bool flag=false;
        int cnt = 0;
        for(auto it:m)
        {
            if(it.second%2==0)
                cnt += it.second;
            else
            {
                flag=true;
                cnt += it.second-1;
            }
        }
        if(flag)
            cnt++;
        return cnt;
    }
};