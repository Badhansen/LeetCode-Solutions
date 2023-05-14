class Solution {
public:
    int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    bool IsLeap(int y) {
        return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
    }
    int DaysFrom1971(string date) {
        int y = stoi(date.substr(0, 4)), m = stoi(date.substr(5, 2)), d = stoi(date.substr(8));
        for (int iy = 1971; iy < y; iy++) {
            d += IsLeap(iy) ? 366 : 365;
        }
        return d + (m > 2 && IsLeap(y)) + accumulate(begin(days), begin(days) + m - 1, 0);
    }
    int daysBetweenDates(string date1, string date2) {
        return abs(DaysFrom1971(date1) - DaysFrom1971(date2));
    }
};