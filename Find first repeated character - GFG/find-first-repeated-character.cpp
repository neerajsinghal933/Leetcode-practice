// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}// } Driver Code Ends


string firstRepChar(string s)
{
    //code here.
    map<char, int>m;
    for(char c:s)
    {
        if(m[c]!=0){
            string t = "";
            t += c;
            return t;
        }
        
        m[c]++;
        
    }
    return "-1";
}