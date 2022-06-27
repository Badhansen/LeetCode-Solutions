// @Author: KING-SEN
// 1 last try

class DetectSquares {
private:
    int points[1005][1005];
public:
    DetectSquares() {
        memset(points, 0, sizeof points);
    }
    
    void add(vector<int> point) {
        points[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int result = 0;
        int x = point[0], y = point[1];
        for(int r = 0; r <= 1000; r++){
            if(r != x && points[r][y]){
                int size = abs(r - x);
                if(y + size <= 1000){
                    result += (points[r][y + size] * points[x][y + size] * points[r][y]);
                }
                if(y - size >= 0){
                    result += (points[r][y - size] * points[x][y - size] * points[r][y]); 
                }
            }
        }
        return result;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */