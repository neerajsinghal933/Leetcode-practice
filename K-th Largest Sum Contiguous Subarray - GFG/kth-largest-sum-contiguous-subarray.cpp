// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &arr,int n,int k){
        vector<int>v;
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            int sum = 0 ;
            for(int j=i;j<n;j++)
            {
                sum += arr[j];
                pq.push(sum);
            }
            
        }
        // while(pq.size())
        // {
        //     cout<<pq.top()<<" ";
        //     pq.pop();
        // }
        // return 0;
        while(k!=1)
        {
            k--;
            pq.pop();
        }
            // pq.pop();
        return pq.top();
        
    }
};

// { Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends