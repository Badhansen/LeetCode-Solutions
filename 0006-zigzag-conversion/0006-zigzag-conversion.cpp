// class Solution {
// public:
//     string convert(string s, int numRows) {
//         if (numRows == 1) {
//             return s;
//         }
//         int n = s.size();
//         int sections = ceil(n / (2.0 * numRows - 2.0));
//         int numCols = sections * (numRows - 1);
//         vector<vector<char>> matrix(numRows, vector<char>(numCols, ' '));
//         int currRow = 0, currCol = 0;
//         int index = 0;
//         while (index < n) {
//             // move down
//             while (currRow < numRows && index < n) {
//                 matrix[currRow][currCol] = s[index];
//                 currRow++;
//                 index++;
//             }
            
//             currRow -= 2;
//             currCol++;
            
//             // move up
//             while (currRow > 0 && currCol < numCols && index < n) {
//                 matrix[currRow][currCol] = s[index];
//                 currCol++;
//                 currRow--;
//                 index++;
//             }
//         }
//         string answer;
//         for (auto &row : matrix) {
//             for (auto &c : row) {
//                 if (c != ' ') {
//                     answer.push_back(c);
//                 }
//             }
//         }
//         return answer;
//     }
// };

// // Time: O(rows * n)
// // Space: O(rows * n);

/*
Intuition

Traverse by index.

Approach

Take a numRows and simulate index in ZigZag Way.
*/
class Solution {
public:
    string convert(string s, int nr) {
        if (s.size() <= nr || nr == 1) return s;
        string ans;

        int a = 2 * nr - 2, b = 0, n = s.size();
        for (int r = 0; r < nr; r++) {
            int i = r;
            while (i < n) {
                if (a && i < n) {
                    ans += s[i], i += a;
                }
                if (b && i < n) {
                    ans += s[i], i += b;
                }
            }
            a -= 2, b += 2;
        }
        return ans;
    }
};

// Time: O(n)
// Space: O(1) // We have not used any additional space other than for building the output, which is not counted.