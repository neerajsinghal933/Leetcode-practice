// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        // Code Here
        int i, j;
        int n = a.size();
        vector<int>v(26, -1);
        for(i=0;i<n;i++)
        {
            if(v[a[i]-'a']==-1)
                v[a[i]-'a'] = i;
        }
        
        for(i=0;i<n;i++)
        {
            bool flag = false;
            for(j=0;j<a[i]-'a';j++)
            {
                if(v[j] > v[a[i]-'a'])
                {
                    flag=true;break;
                }
            }
            if(flag)
            break;
        }
        if(i<n)
        {
            char x = a[i];
            char y = char(j + 'a');
            for(int i=0;i<n;i++)
            {
                if(a[i]==x)
                a[i] = y;
                else if(a[i]==y)
                a[i] = x;
            }
        }
        return a;
        
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends