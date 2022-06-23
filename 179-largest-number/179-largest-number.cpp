class Solution {
public:
    static bool comp(string &a, string &b)
    {
        return a+b>b+a;
}
    
    string largestNumber(vector<int>& nums) {
        vector<string>v;
        // sort(nums.begin(), nums.end(), comp);
        int cnt = 0;
        for(int x:nums)
        {
            v.push_back(to_string(x));
            if(x==0)
            cnt++;
        }
        if(cnt==nums.size())
            return "0";
        sort(v.begin(), v.end(), comp);
        string ans = "";
        for(string s:v)
            ans += s;
        return ans;
    }
};