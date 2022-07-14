class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> event_queue;
        int days = 1, left = 0, right = events.size();
        int result = 0;
        while (!event_queue.empty() || left < right) {
            while (left < right && events[left][0] == days) {
                event_queue.push(events[left][1]);
                left++;
            }
            while (!event_queue.empty() && event_queue.top() < days) {
                event_queue.pop();
            }
            if (!event_queue.empty()) {
                event_queue.pop();
                result++;
            } 
            days++;
        }
        return result;
    }
};
/*
Time O(d + nlogn), where D is the range of A[i][1]
Space O(N)
*/