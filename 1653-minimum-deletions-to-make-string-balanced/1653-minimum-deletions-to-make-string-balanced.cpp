class Solution {
public:
    int minimumDeletions(string s) {
        int ans = INT_MAX;
        int cnt= 0;
        int n = s.size();
        for(char x:s)
        {
            if(x=='b')
                cnt++;
        }
        int b=0, a=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='b')
            {
                b++;
                ans = min(ans, cnt-b+a);
            }
            else
          
                a++;
        }
        ans = min(ans, cnt);
        return ans==INT_MAX?0:ans;
    }
};