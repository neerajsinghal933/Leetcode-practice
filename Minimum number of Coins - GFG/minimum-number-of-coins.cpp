// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int n)
    {
        vector<int>ans;
        while(n)
        {
            if(n>=2000)
            {
                n-=2000;
                ans.push_back(2000);
            }
            else if(n>=500)
            {
                n-=500;
                ans.push_back(500);
            }
            else if(n>=200)
            {
                n-=200;
                ans.push_back(200);
            }
            else if(n>=100)
            {
                n-=100;
                ans.push_back(100);
            }
            else if(n>=50)
            {
                n-=50;
                ans.push_back(50);
            }
            else if(n>=20)
            {
                n-=20;
                ans.push_back(20);
            }
            else if(n>=10)
            {
                n-=10;
                ans.push_back(10);
            }
            else if(n>=5)
            {
                n-=5;
                ans.push_back(5);
            }
            else if(n>=2)
            {
                n-=2;
                ans.push_back(2);
            }
            else if(n>=1)
            {
                n-=1;
                ans.push_back(1);
            }
            
        }
        return ans;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends