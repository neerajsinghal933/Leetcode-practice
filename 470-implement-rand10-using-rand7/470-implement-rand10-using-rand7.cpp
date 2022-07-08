// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        // int a = rand7();
        // int b = rand7()/2;
        // // if(a+b)
        // return a+b;
        int sum = 0;
        for(int i=0;i<10;i++)
            sum += rand7();
        return sum%10+1;
    }
};