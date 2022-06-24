class Solution {
public:
    string getPermutation(int n, int k) {
        k--;
        int fact[n+1];
        vector<int>nums;
        fact[0] = 1;
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
            fact[i] = i * fact[i-1];
        }
        string ans = "";
        while(n>0)
        {
            int z = k / fact[n-1];
            ans += to_string(nums[z]);
            nums.erase(nums.begin()+z);
            k %= fact[n-1];
            n--;
        }   
        return ans;
        
    }
};