class MedianFinder {
private:
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;
public:
    MedianFinder() {
        // leave it as it is.
    }
    
    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        if(lo.size() < hi.size()){
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        double ans = 1.00 * lo.top();
        if(lo.size() == hi.size()){
            ans += hi.top();
            return ans * 0.5;
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */