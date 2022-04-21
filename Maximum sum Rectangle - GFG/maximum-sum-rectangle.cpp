// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int kanade(int arr[], int& start, int& finish, int n)
    {
        int sum = 0, max_sum = INT_MIN, i;
        
        finish = -1;
        int local_start = 0;
        for(i=0;i<n;i++)
        {
            sum += arr[i];
            if(sum<0)
            {
                sum = 0;
                local_start = i+1;
            }
            else if(sum>max_sum)
            {
                max_sum = sum;
                start = local_start;
                finish = i;
            }
        }
        if(finish!=-1)
            return max_sum;
        max_sum = arr[0];
        start = finish = 0;
        for(i=1;i<n;i++)
        {
            if(arr[i]>max_sum)
            {
                max_sum = arr[i];
                start = finish = i;
            }
        }
        return max_sum;
    }
  
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int max_sum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;
        int left, right, i;
        int temp[R], sum, start, finish;
        
        for(left=0; left<C; left++)
        {
            memset(temp, 0, sizeof(temp));
            
            for(right=left; right<C; right++)
            {
                for(i=0; i<R; i++)
                {
                    temp[i] += M[i][right];
                }
                
                sum = kanade(temp, start, finish, R);
                
                if(sum > max_sum)
                {
                    max_sum = sum;
                    finalLeft = left;
                    finalRight = right;
                    finalTop = start;
                    finalBottom = finish;
                }
            }
        }
        return max_sum;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends