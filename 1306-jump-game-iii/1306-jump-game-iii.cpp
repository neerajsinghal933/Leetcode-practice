class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int>vis(n, 0);
        return fun(arr, start, vis);
    }
    
    bool fun(vector<int>&arr, int s, vector<int>&vis)
    {
        
        int n = arr.size();
        if(s<0 or s>=n or vis[s])
            return false;
        vis[s] = true;
        if(arr[s]==0)
            return true;
        return fun(arr, s + arr[s], vis) or fun(arr, s - arr[s], vis);
    }
};