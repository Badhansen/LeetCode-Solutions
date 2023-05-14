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
        vector<pair<int, int>> events; // Pair used as schedule time start, status as starting or ending
        for (auto &list : schedule) {
            for (Interval &interval : list) {
                events.push_back({interval.start, true});
                events.push_back({interval.end, false});
            }
        }
        sort(events.begin(), events.end());
        int prev = -1, employee = 0;
        vector<Interval> answer;
        for (auto event : events) {
            if (employee == 0 and prev != -1) {
                if(prev != event.first) {
                    answer.push_back(Interval(prev, event.first));
                }
            }
            if (event.second) {
                employee++;
            } else {
                employee--;
            }
            if (employee == 0) {
                prev = event.first;
            }
        }
        return answer;
    }
};
/*
Let's break down the time and space complexity for the provided C++ code.

Firstly, the time complexity:

    Iterating over every employee's schedule and adding start and end times to the events vector. Assuming that there are 'n' total intervals across all employees, this operation is O(n) as we are performing a constant time operation for each interval.

    Sorting the events vector. Since we are using the sort function in C++ STL, it uses a comparison based sorting algorithm (Introsort) which runs in O(n log n) time where 'n' is the total number of events.

    Iterating over the sorted events to find the free intervals. This is a linear pass over the 'n' events and hence is O(n).

Therefore, the overall time complexity is dominated by the sorting operation, and is O(n log n).

Now, the space complexity:

    Storing all the events in the events vector. As we store two events (start and end) for each interval, this requires O(n) space.

    Storing the free intervals in the answer vector. In the worst case, if there are free intervals between every pair of intervals, this could require O(n) space as well.

Hence, the overall space complexity is O(n).

Here, 'n' is the total number of intervals across all employees. Note that if you consider 'm' employees and 'k' average intervals per employee, then 'n' would be 'm*k'.
*/
