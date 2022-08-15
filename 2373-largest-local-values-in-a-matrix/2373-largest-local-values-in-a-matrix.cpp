class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> result(n - 2, vector<int> (n - 2));
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                int max_value = 0;
                for (int r = i, rc = 0; r < n && rc < 3; r++, rc++) {
                    for (int c = j, cc = 0; c < n && cc < 3; c++, cc++) {
                        max_value = max(max_value, grid[r][c]);
                    }
                }
                result[i][j] = max_value;
            }
        }
        return result;
    }
};