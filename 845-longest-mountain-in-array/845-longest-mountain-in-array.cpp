class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0;
        int i= 1, j, curr =0;
        int n = arr.size();
        if(n<3)
            return 0;
        while(i<n-1)
        {
            if(arr[i]>arr[i-1] and arr[i]>arr[i+1])
            {
                curr = 1;
                j=i;
                while(j>0 and arr[j]>arr[j-1])
                {
                    curr++;
                    j--;
                }
                j=i;
                while(j<n-1 and arr[j]>arr[j+1])
                {
                    curr++;
                    j++;
                }
                i=j;
            }
            i++;
            ans = max(ans, curr);
        }
        return ans;
    }
};