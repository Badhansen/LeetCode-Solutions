// @Autohor: KING-SEN

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int answer = INT_MAX;
        map<int, set<int>> rows;
        for (auto p : points) {
            int x = p[0], y = p[1];
            rows[x].insert(y);
        }
        for (int i = 0; i < points.size(); i++) {
            for (int j = i; j < points.size(); j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2 || y1 == y2) {
                    continue;
                }
                // (1, 1), (3, 3)
                // (1, 3), (3, 1)
                if (rows[x1].count(y2) && rows[x2].count(y1)) {
                    answer = min(answer, abs(x1 - x2) * abs(y2 - y1));
                }
            }
        }
        return answer == INT_MAX ? 0 : answer;
    }
};

// Time: O(N * N)
// Space: O(N)