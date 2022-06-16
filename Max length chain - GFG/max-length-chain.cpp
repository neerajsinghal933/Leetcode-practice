// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
static bool comp(struct val a, struct val b)
{
    return a.first <= b.first;
}

int maxChainLen(struct val p[],int n)
{
//Your code here
    sort(p, p+n, comp);
    long long last = p[0].second;
    int cnt = 1;
    for(int i=1;i<n;i++)
    {
        if(last < p[i].first)
        {
            cnt++;
            last = p[i].second;
        }
        else
        {
            if(last>p[i].second)
            last = p[i].second;
        }
    }
    return cnt;
    
}