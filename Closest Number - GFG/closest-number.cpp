// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int closestNumber(int n , int m) {
        // code here
        if(n%m==0)
            return n;
        int flag = 0;
        if(m<0 and n<0)
        {
            m= -1*m;
            n = -1*n;
            flag=3;
        }
        else if(n<0)
        {
            n = -1*n;
            flag=1;
        }
        else if(m<0)
        {
            m = -1*m;
            flag = 2;
        }
        int d = n/m;
        int first = m*d;
        int second = m*(d+1);
        if(n-first < second - n)
        {
            if(flag==1 or flag==3)
            {
                return -1 * first;
            }
            else
                return first;
        }
        else
        {
            if(flag==1 or flag==3)
            {
                return -1 * second;
            }
            else
                return second;
        }
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        
        cin>>N>>M;

        Solution ob;
        cout << ob.closestNumber(N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends