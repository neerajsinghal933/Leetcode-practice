class Solution {
public:
    int mySqrt(int x) {
        double l = 0, h = x;
        while(l<=h)
        {
            long long mid = (l+h)/2;
            if(mid*mid==x)
                return (int)mid;
            if(mid*mid<x)
                l = mid+1;
            else
                h = mid-1;
        }
        return h;
    }
};