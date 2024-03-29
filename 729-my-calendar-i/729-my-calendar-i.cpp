class MyCalendar {
public:
    vector<pair<int, int>>v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            if(max(v[i].first, start) < min(end, v[i].second))
                return false;
        }
        v.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */