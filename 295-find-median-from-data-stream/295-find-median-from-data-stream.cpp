#define MAX 100001

template<typename T> void Swap(T& a, T& b){
    T t = a;
    a = b;
    b = t;
}
class MaxHeap{
public:
    int tree[MAX];
    int _size;
    MaxHeap(){
        _size = 0;
    }
    bool empty(){
        return !_size;
    }
    int size(){
        return _size;
    }
    int top(){
        return tree[1];
    }
    void push(int x){
        tree[++_size] = x;
        for(int i = _size; i > 1; i /= 2){
            if(tree[i] > tree[i / 2]){
                Swap(tree[i], tree[i / 2]);
            }
            else break;
        }
    }
    void pop(){
        tree[1] = tree[_size--];
        for(int i = 1; i * 2 <= _size;){
            int k = i * 2 + 1;
            if(i * 2 == _size || tree[k - 1] > tree[k])
                k--;
            if(tree[k] > tree[i]){
                Swap(tree[k], tree[i]);
                i = k;
            }
            else break;
        }
    }
};
class MinHeap{
public:
    int tree[MAX];
    int _size;
    MinHeap(){
        _size = 0;
    }
    bool empty(){
        return !_size;
    }
    int size(){
        return _size;
    }
    int top(){
        return tree[1];
    }
    void push(int x){
        tree[++_size] = x;
        for(int i = _size; i > 1; i /= 2){
            if(tree[i] < tree[i / 2]){
                Swap(tree[i], tree[i / 2]);
            }
            else break;
        }
    }
    void pop(){
        tree[1] = tree[_size--];
        for(int i = 1; i * 2 <= _size;){
            int k = i * 2 + 1;
            if(i * 2 == _size || tree[k - 1] < tree[k])
                k--;
            if(tree[k] < tree[i]){
                Swap(tree[k], tree[i]);
                i = k;
            }
            else break;
        }
    }
};
class MedianFinder {
private:
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;
public:
    MedianFinder() {
        // leave it as it is.
    }
    
    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        if(lo.size() < hi.size()){
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        double ans = 1.00 * lo.top();
        if(lo.size() <= hi.size()){
            ans += hi.top();
            return ans * 0.5;
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */