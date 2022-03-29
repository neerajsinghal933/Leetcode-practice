class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> &temp, int n,unordered_map<int,int> &m)
    {
        if(n==0)
        {
            ans.push_back(temp);
            return;
        }
		
        for(auto &it:m)
        {
            if(it.second<=0) continue;

            it.second--;
            temp.push_back(it.first);
			
            dfs(temp,n-1,m);
			
            temp.pop_back();
            it.second++;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& ar) {
      
        unordered_map<int,int> m;
        for(int i:ar)
        m[i]++;

        vector<int> temp;
        dfs(temp,ar.size(),m);

        return ans;
    }
};