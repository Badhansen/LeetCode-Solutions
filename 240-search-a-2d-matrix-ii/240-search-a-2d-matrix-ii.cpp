static bool     _foo = ios::sync_with_stdio(false);
static ostream* _boo = cin.tie(NULL);

class Solution {
public:
    bool go(vector<vector<int>>& matrix, int target, int up, int down, int left, int right){
         if(up > down || left > right)
            return false;
        int x = (up + down) / 2;
        int y = (left + right) / 2;
        int item = matrix[x][y];
        if(item > target){
            /*
                |1 | 2| 3| 4|
                |5 | 6| 7| 8|
                |9 |10|11|12|
                |13|14|15|16|
            If I want to find 6 and I am in (2, 2) -> 6 so I can't find 6 in this rectangle
                |11|12|
                |15|16|
            so I have 3 rectangles I have to find in this 3 rectangles
                a)
                    |1 | 2| 3| 4|
                    |5 | 6| 7| 8|
                b)
                    |9 |10|
                    |13|14|
            */
            return go(matrix, target, up, x - 1, left, right) || 
                   go(matrix, target, x, down, left, y - 1);
        }
        else if(item < target){
            /*
                |1 | 2|3 | 4|
                |5 | 6|7 | 8|
                |9 |10|11|12|
                |13|14|15|16|
            If I want to find 11 and I am in (1, 1) -> 6 so I can't find 11 in this rectangle
                |1 | 2|
                |5 | 6|
            so I have 2 rectangles I have to find 11 in this 2 rectangles
                a)
                    |3 | 4|
                    |7 | 8|
                    |11|12|
                    |15|16|
                b)
                    |9 |10|
                    |13|14|
            */
            return go(matrix, target, up, down, y + 1, right) ||
                   go(matrix, target, x + 1, down, left, right);
        }
        else 
            return true;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) 
            return false;
        if(matrix[0].size() == 0)
            return false;
        return go(matrix, target, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
    }
};