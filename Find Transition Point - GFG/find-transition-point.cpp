// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    // code here
    int i=0, j=n-1;
    int ans = -1;
    while(i<=j)
    {
        int mid = (i+j)/2;
        if(arr[mid]==1)
        {
            ans = mid;
            j =mid-1;
        }
        else
            i = mid+1;
    }
    return ans;
}