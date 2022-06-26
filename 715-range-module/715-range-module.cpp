// @Author: KING-SEN
// 1 last try

/*
Use a map to save the disjoint intervals. For example, m[left] = right means there is an interval [left, right).

    addRange: Apply removeRange(left, right) at first. Then add a new interval [left, right) in the map. Finally merge the previous interval and the next interval with [left, right) respectively, if they are adjcent.

    queryRange: Use m.upper_bound(left) to find the first interval i that i.left > left. Then we know prev(i).left <= left. If prev(i).right >= right, we should return true, otherwise false.

    removeRange: Find the last interval i that i.left < left. It is also the first interval which this delete operation may influence on. Then check all the intervals after i which intersects with [left, right). Apply delete operation for each interval.
*/


class RangeModule {
private:
    map<int, int> intervals;
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        removeRange(left, right);
        intervals[left] = right;
        auto it = intervals.find(left);
        if(it != intervals.begin() && prev(it)->second == left){
            it--;
            it->second = right;
            intervals.erase(left);
        }
        if(it != prev(intervals.end()) && next(it)->first == right){
            it->second = next(it)->second;
            intervals.erase(next(it));
        }
    }
    
    bool queryRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        if(intervals.empty() || it == intervals.begin()) return false;
        it--;
        return it->second >= right;
    }
    
    void removeRange(int left, int right){
        if(intervals.empty()) return;
        auto it = intervals.lower_bound(left);
        if(it != intervals.begin()) it--;
        vector<int> v;
        while(it != intervals.end() && it->first < right){
            if(it->first < left && it->second > left){
                int temp = it->second;
                it->second = left;
                if(temp > right){
                    intervals[right] = temp;
                }
            }
            else if(it->first >= left){
                v.push_back(it->first);
                if(it->second > right){
                    intervals[right] = it->second;
                }
            }
            it++;
        }
        for(auto i : v) intervals.erase(i);
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