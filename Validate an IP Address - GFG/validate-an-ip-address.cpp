// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            string temp = "";
            int cnt = 0;
            for(char c:s)
            {
                if(!((c>='0' and c<='9') or c=='.'))
                    return 0;
                if(c=='.')
                {
                    cnt++;
                    if(temp.size()<=0 or temp.size()>3)
                        return 0;
                    int n = stoi(temp);
                    if(n!=0 and temp[0]=='0')
                        return 0;
                    if(n==0 and temp.size()!=1)
                        return 0;
                    if(n<0 or n>255)
                        return 0;
                    temp = "";
                }
                else
                    temp += c;
            }
            if(temp.size()<=0 or temp.size()>3)
                return 0;
            int n = stoi(temp);
            if(n!=0 and temp[0]=='0')
                return 0;
            if(n==0 and temp.size()!=1)
                return 0;
            if(n<0 or n>255)
                return 0;
            if(cnt!=3)
                return 0;
            return 1;
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends