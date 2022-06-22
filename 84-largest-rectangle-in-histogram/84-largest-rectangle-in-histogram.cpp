class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
     int ans = INT_MIN, i=0;
        int n = h.size();
        stack<int>s;
        while(i<n)
        {
            if(s.empty() or h[s.top()] <= h[i])
                s.push(i++);
            else
            {
                int top = s.top();
                s.pop();
                int area = h[top] * (s.empty() ? i : i-s.top()-1);
                ans = max(area, ans);
                // s.push(i++);
            }
        }
        while(!s.empty())
        {
             int top = s.top();
                s.pop();
                int area = h[top] * (s.empty() ? i : i-s.top()-1);
                ans = max(area, ans);
        }
        return ans;
    }
};