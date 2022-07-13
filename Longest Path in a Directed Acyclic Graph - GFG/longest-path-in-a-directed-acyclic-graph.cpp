// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
      vector <int> maximumDistance(vector<vector<int>> edges,int n,int e,int src)
      {
            // code here
            vector<int>dist(n, INT_MIN);
            vector<pair<int, int>>adj[n];
            for(auto x:edges)
                adj[x[0]].push_back({x[1], x[2]});
            priority_queue<pair<int, int>>pq;
            pq.push({0, src});
            dist[src] = 0;
            while(!pq.empty())
            {
                int u = pq.top().second;
                int d = pq.top().first;
                pq.pop();
                if(dist[u]>d)
                    continue;
                for(auto x:adj[u])
                {
                    int v = x.first;
                    int dst = x.second;
                    if(dist[u]!=INT_MIN and dist[v]<d + dst)
                    {    
                        dist[v] = d + dst;
                        pq.push({dist[v], v});
                    }
                }
            }
            return dist;
      }
};

// { Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}  // } Driver Code Ends