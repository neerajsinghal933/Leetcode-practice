class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;
        while(b!=0)
        {
            
            unsigned c = a & b;
            a = a^b;
            b = c<<1;
        }
        return a;
    }
};