// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(pair<int, int>&a, pair<int, int>&b)
    {
        return a.first > b.first;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<pair<int, int>>v(n);
        int max_end = 0;
        for(int i=0;i<n;i++)
        {
            v[i] = {arr[i].profit, arr[i].dead};
            max_end = max(max_end, arr[i].dead);
        }
        sort(v.begin(), v.end(), comp);
        vector<int>vis(max_end+1, -1);
        int cnt = 0, maxProfit = 0;
        for(int i=0;i<n;i++)
        {
            int j = v[i].second ;
            while(j>0 and vis[j]!=-1)
                j--;
            if(j>0)
            {
                vis[j] = 1;
                cnt++;
                maxProfit += v[i].first;
            }
        }
        return {cnt, maxProfit};
        
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends