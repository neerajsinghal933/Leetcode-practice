// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char>st;
        for(char c:x)
        {
            if(c=='(' or c=='{' or c=='[')
                st.push(c);
            else if(st.empty())
                return 0;
            else if(c==')' and st.top() == '(')
            {
                st.pop();
                continue;
            }
            else if(c=='}' and st.top() == '{')
            {
                st.pop();
                continue;
            }
            else if(c==']' and st.top() == '[')
            {
                st.pop();
                continue;
            }
            else{
                // cout<<c<<endl;
                return 0;
            }
        }
        // cout<<"kkk";
        return st.empty();
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends