#define MAX_DIRECTION 4

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direction = 0, positionX = 0, positionY = 0;
        for(auto c : instructions){
            if(c == 'G'){
                positionX += move[direction][0];
                positionY += move[direction][1];
            }
            else if(c == 'L'){
                direction = (direction + 1) % MAX_DIRECTION;
            }
            else{
                direction = (direction + 3) % MAX_DIRECTION;
            }
        }
        return (positionX == 0 && positionY == 0) || direction != 0;
    }
};