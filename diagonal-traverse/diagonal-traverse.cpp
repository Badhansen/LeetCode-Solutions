class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int i = 0, j = 0;
        int n = matrix.size();
        int m = n ? matrix[0].size() : 0;
        int x = -1, y = 1;
        vector<int> res;
        while (res.size() < n * m) {
            if (i == n || j == m || j < 0 || i < 0) {
                swap(x, y); // if it has been upward time to reverse it and vice versa.
                if (j == m) // this is just to turn back to the matrix since it is out of bound
                    i += 2, j--;
                else if (i == n)
                    j += 2, i--;
                else {
                    i += i < 0;
                    j += j < 0;
                }
            }
            res.push_back(matrix[i][j]);
            i += x;
            j += y;
        }
        return res;
    }
};