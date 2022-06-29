// @Author: KING-SEN
// 1 last try

class DetectSquares {
private:
    unordered_map<int, unordered_map<int, int>> pointX;
    unordered_map<int, unordered_map<int, int>> pointY;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        pointX[point[0]][point[1]]++;
        pointY[point[1]][point[0]]++;
    }
    
    int count(vector<int> point) {
        int result = 0;
        int px = point[0], py = point[1];
        for(auto [x, val] : pointX[px]){
            int dist = x - py;
            if(x != py){
                result += pointX[px][x] * pointY[py][px + dist] * pointY[x][px + dist];
                result += pointX[px][x] * pointY[py][px - dist] * pointY[x][px - dist];
            }
        }
        return result;
    }
    
    ~DetectSquares() {
        pointX.clear();
        pointY.clear();
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */