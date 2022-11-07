// need to understand this binary search
class MyCalendar {
public:
    MyCalendar() {
        booked.clear();
    }
    
    bool book(int start, int end) {
        end--;
        auto it = booked.lower_bound(start);
        if (it != booked.end() && it->first <= end) return false;
        if (it != booked.begin() && (--it)->second >= start) return false;
        
        booked[start] = end;
        return true;
    }
private:
    map<int, int> booked;
};