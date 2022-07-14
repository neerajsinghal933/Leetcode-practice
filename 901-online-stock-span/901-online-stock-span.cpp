class StockSpanner {
public:
    stack<pair<int, int>>st;
    int idx = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty() and st.top().first <= price)
            st.pop();
        int ans;
        if(st.empty())
            ans = idx+1;
        else
        {
            ans = idx - st.top().second;
        }
        // idx++;
        st.push({price, idx});
        idx++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */