// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends

class Solution{   
public:
    string smallestNumber(int s, int d){
        // code here 
        if((9*d)<s) return "-1";
        string ans = "";
        for(int i=d-1;i>=0;i--)
        {
            if(s>9)
            {
                ans = '9' + ans;
                s -= 9;
            }
            else{
                if(i==0)
                {
                    ans = to_string(s) + ans;
                }
                else
                {
                    ans = to_string(s-1) + ans;
                    i--;
                    while(i>0)
                    {
                        ans = '0' + ans;
                        i--;
                    }
                    ans = '1' + ans;
                    break;
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
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends