/*
More detailed reasoning about the runtime using amortized analysis:

    The total number of elements is bounded by E = O(A + R). (each remove may split one exiting interval into 2 intervals in worst case).
    We can split the summed cost of addRange into two parts:
    a. add one big interval each time which is bounded by O(A*log(E))
    b. remove all intersected intervals which is bounded by O(E).
    removeRange is similar.
    So total runtime is: O((A + R + Q)*log(A + R)), which is amortized O(log(A + R)) for each operation.

*/


class RangeModule {
private:
    map<int, int, greater<int>> intervals;
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        for (auto it = intervals.lower_bound(right); it != intervals.end() && it->second >= left;) {
            left = min(left, it->first);
            right = max(right, it->second);
            it++;
            intervals.erase(prev(it));
        }
        intervals[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = intervals.lower_bound(left);
        if (it == intervals.end()) {
            return false;
        }
        return right <= it->second;
    }
    
    void removeRange(int left, int right){
        for (auto it = intervals.upper_bound(right); it != intervals.end() && it->second > left;) {
            auto nextIt = next(it);
            if (it->second > right) {
                intervals[right] = it->second;
            } 
            if (it->first < left) {
                it->second = left;
            } else {
                intervals.erase(it);
            }
            it = nextIt;
        }
    }
    ~RangeModule() {
        intervals.clear();   
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */