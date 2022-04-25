// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int k = *min_element(arr, arr+n);
	   // cout<<k<<endl;
	   vector<pair<int, int>>v;
	   for(int i=0;i<n;i++)
	    v.push_back({arr[i], i});
	    sort(v.begin(), v.end());
	    sort(arr, arr+n);
	    int ans = -1;
	    int s = 0;
	    int e = n-1;
	    while(s<=e)
	    {
	        int mid = s + (e-s)/2;
	        if(arr[mid]>=k)
	        {
	            
	            ans = mid;
	            e = mid-1;
	        }
	        else
	        s = mid+1;
	    }
	   // cout<<v[ans].first<<" ";
	    return v[ans].second;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends