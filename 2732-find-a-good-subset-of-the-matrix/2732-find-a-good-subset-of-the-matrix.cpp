class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<int> sums;
        for (int i = 0; i < r; i++) {
            int num = 0;
            for (int j = 0; j < c; j++) {
                if (grid[i][j]) {
                    num |= (1 << j);
                }
            }
            if (!num) {
                return {i};
            }
            sums.push_back(num);
        }
        for (int i = 0; i < r; i++) {
            for (int j = i + 1; j < r; j++) {
                if ((sums[i] & sums[j]) == 0) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
