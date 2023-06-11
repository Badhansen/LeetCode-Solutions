/*
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
*/
/*
Time: O(Row ^ 2)
Space: O(Row)

*/
class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int n = (1 << c);
        vector<int> maps(n, -1);
        for (int i = 0; i < r; i++) {
            int sum = 0;
            for (int j = 0; j < c; j++) {
                if (grid[i][j]) {
                    sum |= (1 << j);
                }
            }
            if (!sum) {
                return {i};
            }
            maps[sum] = i;
        }
        for (int i = 0; i < n; i++) {
            if (maps[i] == -1) {
                continue;
            }
            for (int j = i + 1; j < n; j++) {
                if (maps[j] == -1) {
                    continue;
                }
                if ((i & j) == 0) {
                    
                    return {min(maps[i], maps[j]), max(maps[i], maps[j])};
                }
            }
        }
        return {};
    }
};

