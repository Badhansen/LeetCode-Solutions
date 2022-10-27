class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int result = 0;
        int n = img1.size();
        map<array<int, 2>, int> count;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        if (img1[i][j] && img2[k][l]) {
                            result = max(result, ++count[{i - k, j - l}]);
                        }
                    }
                }
            }
        }
        return result;
    }
};