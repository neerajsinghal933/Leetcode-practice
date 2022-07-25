class Solution {
public:
    double myPow(double x, long n) {
        if(n==0)
            return 1.0;
        
        if(n<0)
        {
            x = 1.0/(double)x;
            n = -n;
            return myPow(x, n);
        }
        // x = x*x;
        double res = myPow(x, n/2);
        if(n%2)
            return x*res*res;
        else
            return res*res;
    }
};