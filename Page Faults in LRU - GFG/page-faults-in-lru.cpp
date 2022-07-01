// { Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int n, int c, int pages[]){
        // code here
        list<int>q;
        unordered_map<int, list<int>::iterator>mp;
        
        int i=0;
        // int size =0;
        int cnt = 0;
        while(i<n)
        {
            if(mp.find(pages[i])==mp.end())
            {
                if(q.size()>=c)
                {
                    int t = q.front();
                    mp.erase(t);
                    q.pop_front();
                }
                q.push_back(pages[i]);
                auto it = q.end();
                it--;
                mp[pages[i]] = it;
                cnt++;
            }
            else
            {
                q.erase(mp[pages[i]]);
                q.push_back(pages[i]);
                auto itr = q.end();
                itr--;
                mp[pages[i]] = itr;
            }
            i++;
        }
        return cnt;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}  // } Driver Code Ends