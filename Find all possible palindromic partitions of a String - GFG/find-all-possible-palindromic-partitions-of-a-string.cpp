// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    bool isPalin(string &s)
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=s[s.size()-1-i])
                return false;
        }
        return true;
    }
  
    void fun(string &s, vector<vector<string>>&res, vector<string>&temp)
    {
        if(s.size()==0)
        {
            res.push_back(temp);
            return;
        }
        string t = "";
        for(int i=0;i<s.size();i++)
        {
            t += s[i];
            if(isPalin(t))
            {
                temp.push_back(t);
                string s1 = s.substr(i+1);
                fun(s1, res, temp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
        
        vector<vector<string>>res;
        vector<string>temp;
        fun(s, res, temp);
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends