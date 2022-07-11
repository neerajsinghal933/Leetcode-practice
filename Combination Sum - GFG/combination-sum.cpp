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
    set<vector<int>>st;
    vector<vector<int> > combinationSum(vector<int> &a, int b) {
        // Your code here
        vector<vector<int>>res;
        vector<int>temp;
        sort(a.begin(), a.end(), greater<int>());
        fun(a, b, temp, res, a.size());
        for(auto x:st)
            res.push_back(x);
        return res;
    }
    
    void fun(vector<int>&a, int b, vector<int>temp, vector<vector<int>>&res, int n)
    {
        if(n==0 or b==0)
        {
            if(b==0)
                st.insert(temp);
            return;
        }
        if(a[n-1]<=b)
        {
            temp.push_back(a[n-1]);
            fun(a, b-a[n-1], temp, res, n);
            temp.pop_back();
        }
        else
            return;
        int k;
        for(k = n-1;k>0;k--)
        {
            if(a[k]==a[k-1])
                n = k-1;
            else
                break;
        }
        fun(a, b, temp, res, k);
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