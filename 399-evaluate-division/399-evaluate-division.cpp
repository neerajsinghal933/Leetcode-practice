class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double>ans;
        map<string, double>mp;
        map<string, vector<string>>graph;
        
        for(int i=0;i<equations.size();i++)
        {
            string u = equations[i][0];
            string v = equations[i][1];
            mp[u+"->"+v] = values[i];
            mp[v+"->"+u] = 1.0/values[i];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
       for(int i=0;i<queries.size();i++)
        {
            
            bool found = false;
            double val = 1;
           map<string, int>vis;
            string start = queries[i][0];
           string end = queries[i][1];
           if(graph.find(start)==graph.end() or graph.find(end)==graph.end())
           {
               ans.push_back(-1);
               continue;
           }
           else if(start==end)
           {
               ans.push_back(val);
               continue;
           }
           else
           {
               dfs(start, end, mp, graph, found, val, vis);
               if(found)
                   ans.push_back(val);
               else
                   ans.push_back(-1);
           }
        }
        return ans;
    }
    
    void dfs(string &start, string &end, map<string, double>&mp, map<string, vector<string>>&graph, bool &found, double &val, map<string, int>&vis)
    {
        vis[start] = 1;
        if(found)
            return;
        for(string s:graph[start])
        {
            if(!vis[s])
            {
                val *= mp[start + "->" + s];
                if(end==s)
                {
                    found = true;
                    return ;
                }
                dfs(s, end, mp, graph, found, val, vis);
                if(found)
                    return;
                else
                    val /= mp[start+"->"+s];
            }
        }
    }
};