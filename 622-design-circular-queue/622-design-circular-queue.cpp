class MyCircularQueue {
private:
    int arr[1000011];
    int fr, ed, K;
public:
    MyCircularQueue(int k) {
        fr = ed = 0;
        K = k;
    }
    
    bool enQueue(int value) {
        if(ed - fr >= K) return false;
        arr[ed++] = value;
        return true;
    }
    
    bool deQueue() {
        if(fr == ed) return false;
        fr++;
        return true;
    }
    
    int Front() {
        if(fr == ed) return -1;
        return arr[fr];
    }
    
    int Rear() {
        if(fr == ed) return -1;
        return arr[ed - 1];
    }
    
    bool isEmpty() {
        if(fr == ed) return true;
        return false;
    }
    
    bool isFull() {
        if(ed - fr >= K) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */