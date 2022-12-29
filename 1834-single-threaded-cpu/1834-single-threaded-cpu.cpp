class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size(), index = 0;
        vector<vector<int>> stasks;
        for (int i = 0; i < n; i++) {
            stasks.push_back({tasks[i][0], tasks[i][1], i});
        }
        sort(stasks.begin(), stasks.end());
        int endtime = stasks[index][0];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> que;
        vector<int> answer;
        while (index < n) {
            if (!que.empty()) {
                answer.push_back(que.top()[1]);
                endtime += que.top()[0];
                que.pop();
            }
            while (index < n && stasks[index][0] <= endtime) {
                que.push({stasks[index][1], stasks[index][2], stasks[index][0]});
                index++;
            }
            if (index < n && endtime < stasks[index][0] && que.empty()) {
                endtime = stasks[index][0];
            }
        }
        while (!que.empty()) {
            answer.push_back(que.top()[1]);
            que.pop();
        }
        return answer;
    }
};