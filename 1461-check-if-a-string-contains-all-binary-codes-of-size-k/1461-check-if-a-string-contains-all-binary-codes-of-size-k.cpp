class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string>st;
        int n = s.size();
        for(int i=0;i<n-k+1;i++)
        {
            string t = s.substr(i, k);
            st.insert(t);
        }
        int target = pow(2, k);
        if(st.size()==target)
            return true;
        return false;
    }
};