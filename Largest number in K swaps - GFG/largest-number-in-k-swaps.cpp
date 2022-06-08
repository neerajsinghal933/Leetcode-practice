// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans;
       fun(str, ans, k, 0);
       return ans;
    }
    
    void fun(string &str, string &ans, int k, int idx)
    {
        if(k==0)
            return;
        int n = str.length();
        char c = str[idx];
        for(int i=idx+1;i<n;i++)
        {
            if(str[i]>c)
                c = str[i];
        }
        if(c!=str[idx])
            k--;
        for(int i=idx+1;i<n;i++)
        {
            if(str[i]==c)
            {
                swap(str[i], str[idx]);
                ans = max(str, ans);
                fun(str, ans, k, idx+1);
                swap(str[i], str[idx]);
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends