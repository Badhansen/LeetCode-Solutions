// Time Complexity: O(m * n)
// Space Complexity: O(m + n);

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxx = INT_MIN;
        set<int> row, column;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!matrix[i][j]){
                    row.insert(i);
                    column.insert(j);
                }
            }
        }
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                if(row.count(i) || column.count(j)){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};