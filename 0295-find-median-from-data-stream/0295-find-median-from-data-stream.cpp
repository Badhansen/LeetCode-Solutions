class MedianFinder {
private:
    // left = max heap
    // right = min heap
    multiset<int> left, right;
public:
    MedianFinder() {
        // leave it as it is.
    }
    
    void addNum(int num) {
        left.insert(num);
        right.insert(*left.rbegin());
        left.erase(prev(left.end()));
        if(left.size() < right.size()){
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    }
    
    double findMedian() {
        double ans = 1.00 * (*left.rbegin());
        if(left.size() == right.size()){
            ans += (*right.begin());
            ans /= 2.00;
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