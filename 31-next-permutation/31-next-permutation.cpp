class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int n = v.size(),i,j;
        for(i=n-2;i>=0;i--)
        {
            if(v[i]<v[i+1])
                break;
        }
        if(i<0)
            reverse(v.begin(),v.end());
        else
        {
            for(j=n-1;j>i;j--)
            {
                if(v[j] > v[i])
                    break;
            }
            swap(v[i],v[j]);
            reverse(v.begin()+i+1, v.end());
        }
    }
};