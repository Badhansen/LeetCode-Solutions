class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int row = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < m; j++) {
                count += mat[i][j];
            }
            if (count > ans) {
                ans = count;
                row = i;
            }
        }
        return {row, ans};
    }
};