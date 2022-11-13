//@Author: KING-SEN

class MovingAverage {
private: 
    queue<int> store;
    double sum;
    int window; 
public:
    MovingAverage(int size) {
        store = queue<int>();
        sum = 0;
        window = size;
    }
    
    double next(int val) {
        store.push(val);
        sum += val;
        if(store.size() > window) {
            sum -= store.front();
            store.pop();
        }
        return (double) sum / store.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
/*
Time: O(N)
Space: O(M)
*/