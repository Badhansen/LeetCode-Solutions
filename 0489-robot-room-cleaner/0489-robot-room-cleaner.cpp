//@Author: KING-SEN

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
private:
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    unordered_map<int, unordered_map<int,int>> isSeen;
    
    void goback(Robot& robot){
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
    
    void dfs(int x, int y, int dir, Robot& robot){
        isSeen[x][y] = 1;
        robot.clean();
        for(int i=0; i<4; i++){
            
            int nextX = dx[dir] + x;
            int nextY = dy[dir] + y;
            
            if(robot.move() && isSeen[nextX][nextY] == 0){
                dfs(nextX, nextY, dir, robot);
            }

            robot.turnRight();
            dir = (dir+1)%4;
        } 
        goback(robot);
    }
    
   
    
    void backtrack(int row, int col, int dir, Robot& robot){
        isSeen[row][col] = 1;
        robot.clean();
        
        for(int i=0; i<4; i++){
            int nextRow = row + dx[dir];
            int nextCol = col + dy[dir];
            
            if(isSeen[nextRow][nextCol] == 0 && robot.move()){
                backtrack(nextRow, nextCol, dir, robot);
            }
            
            robot.turnRight();
            dir = (dir+1)%4;
        }
        goback(robot);
    }
    
public:
    void cleanRoom(Robot& robot) {
        isSeen.clear();
        backtrack(0, 0, 0, robot);
    }
};