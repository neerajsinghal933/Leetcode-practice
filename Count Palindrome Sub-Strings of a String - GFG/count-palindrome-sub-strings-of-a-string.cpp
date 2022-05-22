// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}

// } Driver Code Ends

int dp[1001][1001];
bool fun(int, int, string&);
int CountPS(char c[], int n)
{
    //code here
    int cnt =0;
    string s = "";
    for(int i=0;i<n;i++)
        s += c[i];
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(fun(i, j, s))
            cnt++;
        }
    }
    return cnt;
    
}

bool fun(int i, int j, string& s)
{
    if(i>j)
        return 1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s[i]!=s[j])
    return dp[i][j] = 0;
    return dp[i][j] = fun(i+1, j-1, s);
}