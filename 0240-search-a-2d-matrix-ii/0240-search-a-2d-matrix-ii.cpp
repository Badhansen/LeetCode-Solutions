class Solution {
public:
//     bool go(vector<vector<int>>& matrix, int target, int up, int down, int left, int right){
//         if(up > down || left > right) {
//             return false;
//         }
//         int x = (up + down) / 2;
//         int y = (left + right) / 2;
//         int item = matrix[x][y];
//         if(item > target){
//             /*
//                 |1 | 2| 3| 4|
//                 |5 | 6| 7| 8|
//                 |9 |10|11|12|
//                 |13|14|15|16|
//             If I want to find 6 and I am in (2, 2) -> 6 so I can't find 6 in this rectangle
//                 |11|12|
//                 |15|16|
//             so I have 3 rectangles I have to find in this 3 rectangles
//                 a)
//                     |1 | 2| 3| 4|
//                     |5 | 6| 7| 8|
//                 b)
//                     |9 |10|
//                     |13|14|
//             */
//             return go(matrix, target, up, x - 1, left, right) || 
//                    go(matrix, target, x, down, left, y - 1);
//         }
//         else if(item < target){
//             /*
//                 |1 | 2|3 | 4|
//                 |5 | 6|7 | 8|
//                 |9 |10|11|12|
//                 |13|14|15|16|
//             If I want to find 11 and I am in (1, 1) -> 6 so I can't find 11 in this rectangle
//                 |1 | 2|
//                 |5 | 6|
//             so I have 2 rectangles I have to find 11 in this 2 rectangles
//                 a)
//                     |3 | 4|
//                     |7 | 8|
//                     |11|12|
//                     |15|16|
//                 b)
//                     |9 |10|
//                     |13|14|
//             */
//             return go(matrix, target, up, down, y + 1, right) ||
//                    go(matrix, target, x + 1, down, left, right);
//         }
//         else 
//             return true;
//     }
//     bool Search(const vector<vector<int>>& matrix, int target, int left, int right, int up, int down) {
//         if (left > right || up > down) {
//             return false;
//         }
//         int x = (up + down) / 2;
//         int y = (left + right) / 2;
//         int value = matrix[x][y];
//         if (value == target) {
//             return true;
//         } else if (value > target) {
//             return Search(matrix, target, left, right, up, x - 1) || Search(matrix, target, left, y - 1, x, down); 
//         } else {
//             return Search(matrix, target, y + 1, right, up, down) || Search(matrix, target, left, right, x + 1, down);
//         }
//     }
//
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int r = 0, c = matrix[0].size() - 1;
        while (r < n && c >= 0) {
            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] > target) {
                c--;
            } else {
                r++;
            }
        }
        return false;
    }
};