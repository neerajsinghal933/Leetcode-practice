// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	vector<string>res;
	set<string>st;
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    fun(S, 0, S.size()-1);
		    for(auto it:st)
		        res.push_back(it);
		    return res;
		}
		
		void fun(string s, int i, int j)
		{
		    if(i==j)
		    {
		        st.insert(s);
		        return;
		    }
		    for(int k=i;k<=j;k++)
		    {
		        swap(s[i], s[k]);
		        fun(s, i+1, j);
		        swap(s[i], s[k]);
		    }
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends