//@Author: KING-SEN

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix.size() != matrix[0].size()) return;
        reverse(matrix.begin(), matrix.end());
        // for (auto r : matrix) {
        //     for (auto c : r) {
        //         cout << c << " ";
        //     }
        //     cout << endl;
        // }
        int n = matrix.size();
        for(int row = 0; row < n; row++){
            for(int col = row + 1; col < n; col++){
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }
};
/*
[

7 8 9 
4 5 6 
1 2 3 

]

*/
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         if(matrix.size() == 0 || matrix.size() != matrix[0].size()) return;
//         int n = matrix.size();
//         for(int i = 0; i < n / 2; i++){
//             for(int j = i; j < n - i - 1; j++){
//                 // save the top element
//                 int top = matrix[i][j];
//                 // top <- left
//                 matrix[i][j] = matrix[n - j - 1][i];
//                 // left <- bottom
//                 matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
//                 // bottom <- right
//                 matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
//                 // right <- top
//                 matrix[j][n - i - 1] = top;
//             }
//         }
//     }
// };
