class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string t = strs[0];
        if(strs.size()==1)
            return t;
        int k = 0;
        while(1)
        {
            k++;
            string temp = t.substr(0, k);
            bool flag = false;
            for(int i=1;i<strs.size();i++)
            {
                if(strs[i].size()==0)
                    return "";
                if(strs[i].size()<k or strs[i].substr(0, k)!=temp)
                {
                    flag=true;break;
                }
            }
            if(flag)
                break;
        }
        return t.substr(0, k-1);
    }
};