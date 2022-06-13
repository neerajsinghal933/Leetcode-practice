// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        unordered_map<char, int>m;
        for(char c:p)
            m[c]++;
        int n = s.size();
        int k = p.size();
        if(k>n)
            return "-1";
        string ans = "-1";
        int ans_sz = INT_MAX;
        int j=0, matched = 0;
        for(int i=0;i<n;i++)
        {
            if(m.find(s[i])!=m.end())
            {
                m[s[i]]--;
                if(m[s[i]]>=0)
                    matched++;
                while(matched==k)
                {
                    if(i-j+1<ans_sz)
                    {
                        ans_sz = i-j+1;
                        ans = s.substr(j, i-j+1);
                    }
                    if(m.find(s[j])!=m.end())
                    {
                        m[s[j]]++;
                        if(m[s[j]]>0)
                            matched--;
                    }
                    j++;
                }
            }
        }
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends