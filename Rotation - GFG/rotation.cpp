// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int nums[], int n) {
	    // code here
	    int s = 0;
        int e = n-1;
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if((mid-1<0 or nums[mid-1]>nums[mid]) and (mid+1==n or nums[mid]<nums[mid+1]))
                return mid;
            if(nums[mid]>nums[n-1])
                s = mid+1;
            else
                e = mid-1;
        }
        return 0;
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