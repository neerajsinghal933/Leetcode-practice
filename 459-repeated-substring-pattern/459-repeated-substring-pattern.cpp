class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i=1;i<n;i++)
        {
            if(n%i!=0)
                continue;
            bool flag = false;
            string first = s.substr(0, i);
            for(int j=0;j<n;j+=i)
            {
                string second = s.substr(j, i);
                if(first!=second)
                {
                    flag = 1;
                    break;
                }
            }
            if(!flag)
                return true;
        }
        return false;
    }
};