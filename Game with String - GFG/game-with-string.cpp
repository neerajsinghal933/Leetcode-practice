// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        map<char, int>m;
        for(char c:s)
            m[c]++;
        priority_queue<pair<int, char>>pq;
        for(auto it:m)
            pq.push({it.second, it.first});
        // while(!pq.empty())
        // {
        //     cout<<pq.top().first<<" "<<pq.top().second<<endl;
        //     pq.pop();
        // }
        // return 0;
        while(k--)
        {
            int t = pq.top().first;
            char c = pq.top().second;
            pq.pop();
            
            t--;
            if(t>0)
                pq.push({t, c});
        }
        // while(!pq.empty())
        // {
        //     cout<<pq.top().first<<" "<<pq.top().second<<endl;
        //     pq.pop();
        // }
        // return 0;
        int cnt = 0;
        while(!pq.empty())
        {
            cnt += pow( pq.top().first, 2);
            pq.pop();
        }
        return cnt;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}  // } Driver Code Ends