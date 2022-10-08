class MyCalendarThree {
private:
    map<int, int> count;
public:
    MyCalendarThree() {}
    
    int book(int start, int end) {
        int curr = 0, res = 0;
        count[start]++;
        count[end]--;
        for (auto [key, value] : count) {
            curr += value;
            res = max(curr, res);
        }
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */