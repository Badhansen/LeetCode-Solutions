class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans, line;
        for (int i = 0; i < obstacles.size(); i++) {
            int len = upper_bound(line.begin(), line.end(), obstacles[i]) - line.begin();
            if (len == line.size()) {
                line.push_back(obstacles[i]);
            } else {
                line[len] = obstacles[i];
            }
            ans.push_back(len + 1);
        }
        return ans;
    }
};