class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<array<int, 2>> costs;
        for (int i = 0; i < n; i++) {
            costs.push_back({capital[i], profits[i]});
        }
        sort(costs.begin(), costs.end(), [&](auto a, auto b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        int index = 0;
        priority_queue<int> que;
        while (k--) {
            while (index < n && costs[index][0] <= w) {
                que.push(costs[index][1]);
                index++;
            }
            if (que.empty()) {
                break;
            }
            w += que.top();
            que.pop();
        }
        return w;
    }
};