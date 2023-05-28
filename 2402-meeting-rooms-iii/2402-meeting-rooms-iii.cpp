class Solution {
public:
    struct compare {
        bool operator()(const pair<long long, int>& a, const pair<long long, int>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first > b.first;
        }  
    };
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, compare> que;
        vector<int> count(n, 0);
        for (int i = 0; i < n; i++) {
            que.push({meetings[0][0], i});
        }
        for (auto &meeting : meetings) {
            long long start = meeting[0], end = meeting[1];
            while (que.top().first < start) {
                que.push({start, que.top().second});
                que.pop();
            }
            auto [time, room] = que.top();
            que.pop();
            count[room]++;
            que.push({time + end - start, room});
        }
        return max_element(count.begin(), count.end()) - count.begin();
    }
};