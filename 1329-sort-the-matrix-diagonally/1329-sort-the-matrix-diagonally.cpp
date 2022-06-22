class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, priority_queue<int, vector<int>, greater<int>> > que;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                que[i - j].push(mat[i][j]);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mat[i][j] = que[i - j].top();
                que[i - j].pop();
            }
        }
        return mat;
    }
};

// Time: O(M * N log (Length of the diagonal))
// Space: O(M * N)