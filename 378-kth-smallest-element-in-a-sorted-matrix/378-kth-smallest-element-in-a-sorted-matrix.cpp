class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size();
        priority_queue<int> que;
        for(int r = 0; r < row; r++){
            for(int c = 0; c < col; c++){
                que.push(matrix[r][c]);
                if(que.size() > k) que.pop();
            }
        }
        return que.top();
    }
};