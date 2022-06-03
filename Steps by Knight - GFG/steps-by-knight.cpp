// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    vector<int>dirX = {2, 2, -2, -2, 1, 1, -1, -1};
	 vector<int>dirY = {1, -1, 1, -1, 2, -2, 2, -2};
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int n)
	{
	    // Code here
	    KnightPos[0]--;
	    KnightPos[1]--;
	    TargetPos[0]--;
	    TargetPos[1]--;
	    
	    vector<vector<int>>vis(n, vector<int>(n, 0));
	    queue<pair<int, int>>q;
	    if(KnightPos[0] == TargetPos[0] and KnightPos[1] == TargetPos[1])
	        return 0;
	    q.push({KnightPos[0], KnightPos[1]});
	    int cnt = 0;
	    while(!q.empty())
	    {
	        int sz = q.size();
	        cnt++;
	        for(int i=0;i<sz;i++)
	        {
	            int x = q.front().first;
	            int y = q.front().second;
	            q.pop();
	            for(int k=0;k<8;k++)
	            {
	                int currX = x + dirX[k];
	                int currY = y + dirY[k];
	                if(currX == TargetPos[0] and currY == TargetPos[1])
	                    return cnt;
	                if(currX>=0 and currX<n and currY>=0 and currY<n and !vis[currX][currY])
	                {
	                    vis[currX][currY] = 1;
	                    q.push({currX, currY});
	                }
	            }
	        }
	    }
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends