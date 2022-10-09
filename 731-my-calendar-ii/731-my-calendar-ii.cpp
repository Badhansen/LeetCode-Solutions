class MyCalendarTwo {
private:
    map<int, int> events;
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        int booked = 0;
        events[start]++;
        events[end]--;
        for (auto [key, value] : events) {
            booked += value;
            if (booked == 3) {
                events[start]--;
                events[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */