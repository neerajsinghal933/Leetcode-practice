// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    map<vector<int>, int>m;
    vector<vector<int> > combinationSum(vector<int> &a, int b) {
        // Your code here
        int n = a.size();
        sort(a.begin(), a.end());
        auto ip = std::unique(a.begin(), a.begin() + n);
        a.resize(std::distance(a.begin(), ip));
        n = a.size();
        vector<vector<int>>ans;
        vector<int>temp;
        fun(a, b, temp, ans, 0);
        return ans;
    }
    
    void fun(vector<int>&a, int b, vector<int>temp, vector<vector<int>>&ans, int idx)
    {
        if(idx>=a.size() and b==0)
        {
            if(m[temp]==0)
                ans.push_back(temp);
            m[temp]++;
            return;
        }
        if(b==0)
        {
            if(m[temp]==0)
                ans.push_back(temp);
            m[temp]++;
            return;
        }
        if(idx>=a.size())
            return;
        if(b-a[idx]>=0)
        {
            temp.push_back(a[idx]);
            fun(a, b-a[idx], temp, ans, idx);
            temp.pop_back();
        }
        fun(a, b, temp, ans, idx+1);
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends