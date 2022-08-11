
class Solution {
public:
    
    string pushDominoes(string v) {
        int n = v.size();
        int INF  = INT_MAX;
        vector<int>left(n, INF), right(n, INF);
        for(int i=0;i<n;i++)
        {
            if(v[i]=='R')
                right[i] = 0;
            else if(v[i]=='L')
                continue;
            else if(i!=0 and right[i-1]!=INF)
                right[i] = right[i-1] + 1;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(v[i]=='L')
                left[i] = 0;
            else if(v[i]=='R')
                continue;
            else if(i!=n-1 and left[i+1]!=INF)
                left[i] = left[i+1] + 1;
        }
        // for(int i=0;i<n;i++)
        // {
        //     if(right[i]==INF)
        //         cout<<"L ";
        //     else
        //     cout<<right[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++)
        // {
        //     if(left[i]==INF)
        //         cout<<"L ";
        //     else
        //     cout<<left[i]<<" ";
        // }
        string ans = "";
        for(int i=0;i<n;i++)
        {
            if(right[i]<left[i])
                ans += "R";
            else if(right[i]>left[i])
                ans += "L";
            else
                ans += ".";
        }
        // cout<<endl;
        return ans;
    }
};