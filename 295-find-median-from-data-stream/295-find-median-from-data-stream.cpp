class MedianFinder {
public:
    priority_queue<int>pq;
    priority_queue<int, vector<int>, greater<int>>pq1;
    int n1 = 0, n2 = 0;
    MedianFinder() {
        n1 = 0;
        n2 = 0;
    }
    
    void addNum(int num) {
        pq.push(num);
        int t = pq.top();
        pq.pop();
        pq1.push(t);
        if(n2>n1)
        {
            pq.push(pq1.top());
            pq1.pop();
            n1++;
        }
        else
            n2++;
    }
    
    double findMedian() {
        if(n1==0 and n2==0)
            return -1;
        if(n2>n1)
            return pq1.top();
        return (pq.top() + pq1.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */