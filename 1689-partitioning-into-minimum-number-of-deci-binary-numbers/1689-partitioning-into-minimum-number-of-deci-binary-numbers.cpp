class Solution {
public:
    int minPartitions(string n) {
        char mx = '0';
        for(char c:n)
            mx = max(c, mx);
        return mx-'0';
    }
};