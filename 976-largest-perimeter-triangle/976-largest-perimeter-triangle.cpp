class Solution {
public:
    int largestPerimeter(vector<int>& v) {
        int n = v.size();
        
        sort(v.begin(), v.end());
        
        for(int i=n-1;i>=2;i--)
        {
            int a = v[i];
            int b = v[i-1];
            int c = v[i-2];
            if(a+b>c and a+c>b and b+c>a)
                    return a+b+c;
        }
        return 0;
    }
};