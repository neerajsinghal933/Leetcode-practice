class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int>q;
        int i;
        for(i=1;i<n;i++)
        {
            int diff = heights[i] - heights[i-1];
            if(diff>0)
            {
                if(diff<=bricks)
                {
                    q.push(diff);
                    bricks -= diff;
                }
                else if(ladders>0)
                {
                    ladders--;
                    if(q.size() and q.top()>diff)
                    {
                        int t = q.top();
                        q.pop();
                        bricks += t;
                        bricks-=diff;
                        q.push(diff);
                    }
                }
                else
                    break;
            }
        }
        return i-1;
    }
};