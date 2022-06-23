class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1)
            return true;
        return fun(n);
    }
    
    bool fun(int n)
    {
        if(n%3!=0 or n==0)
            return false;
        if(n/3==1)
            return true;
        return fun(n/3);
    }
};