// @Author: KING-SEN

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> grid(3, vector<int>(3, 2));
        int player = 1;
        for(auto m : moves){
            grid[m[0]][m[1]] = player;
            player = !player;
        }
        for(int i = 0; i < 3; i++){
            if((grid[0][i] == 1 && grid[1][i] == 1 && grid[2][i] == 1) || (grid[i][0] == 1 && grid[i][1] == 1 && grid[i][2] == 1)){
                return "A";
            }
            if((grid[i][0] == 0 && grid[i][1] == 0 && grid[i][2] == 0) || (grid[0][i] == 0 && grid[1][i] == 0 && grid[2][i] == 0)){
                return "B";
            }
        }
        if((grid[0][0] == 1 && grid[1][1] == 1 && grid[2][2] == 1) || (grid[0][2] == 1 && grid[1][1] == 1 && grid[2][0] == 1)){
            return "A";
        }
        if((grid[0][0] == 0 && grid[1][1] == 0 && grid[2][2] == 0) || (grid[0][2] == 0 && grid[1][1] == 0 && grid[2][0] == 0)){
            return "B";
        }
        if(moves.size() < 9){
            return "Pending";
        }
        return "Draw";
    }
};