// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    static bool comp(vector<int>&a, vector<int>&b)
    {
        return a[1]>b[1];
    }
    
    vector<vector<int>> overlappedInterval(vector<vector<int>>& v) {
         // Code here
         sort(v.begin(), v.end());
         vector<vector<int>>ans;
         int s = v[0][0], e = v[0][1];
         for(int i=1;i<v.size();i++)
         {
             if(v[i][0] > e)
             {
                 ans.push_back({s, e});
                 s = v[i][0];
                 e = v[i][1];
             }
             else
             {
                 s = min(s, v[i][0]);
                 e = max(e, v[i][1]);
             }
         }
        //  if(ans.size()==0)
            ans.push_back({s, e});
         return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends