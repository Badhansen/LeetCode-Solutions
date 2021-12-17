class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int R = matrix.size();
        if(R == 0 || matrix[0].empty()) return 0;
        int C = matrix[0].size();
        vector<vector<int>> dp(R, vector<int>(C));
        int answer = 0;
        for(int row = 0; row < R; row++){
            for(int col = 0; col < C; col++){
                if(matrix[row][col] == '1'){
                    dp[row][col] = 1;
                    if(row > 0 && col > 0){
                        dp[row][col] += min({dp[row - 1][col - 1], dp[row - 1][col], dp[row][col - 1]});
                    }
                    answer = max(answer, dp[row][col]);
                }
            }
        }
        return answer * answer;
    }
};