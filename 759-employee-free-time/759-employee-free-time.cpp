/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
/*
Thought
Most interval-related problems can be solved by the Sweep-line algorithm.
Logic
Free time is a period of time such that no employees scheduled to work, i.e. the gap between every two non-overlapping intervals. If we meet a start of interval, score++; or else(if we meet an end of interval), score--. Non-overlapping intervals exist when score equals to 0.
We add current gap interval to the result list when score is not 0 any more.
*/

// @Author: KING-SEN

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        map<int, int> events; // key: time point, value: total employee
        for (auto &list : schedule) {
            for (Interval &interval : list) {
                events[interval.start]++;
                events[interval.end]--;
            }
        }
        int start = -1, employee = 0;
        vector<Interval> answer;
        for (auto const& [time, count] : events) {
            employee += count;
            if (start == -1 && employee == 0) {
                start = time;
            } else if (start != -1 && employee != 0) {
                answer.push_back(Interval(start, time));
                start = -1;
            }
        }
        return answer;
    }
};

