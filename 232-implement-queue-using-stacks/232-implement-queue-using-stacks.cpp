// @Author: KING-SEN
// 1 last try
class MyQueue {
private:
    stack<int> stackOne, stackTwo;
    int front;
public:
    MyQueue() {
        
    }
    void push(int x) { // O(1)
        if(stackOne.empty()){
            front = x;
        }
        stackOne.push(x);
    }
    int pop() { // Amortized O(1)
        if(stackTwo.empty()){
            while(!stackOne.empty()){
                stackTwo.push(stackOne.top());
                stackOne.pop();
            }
        }
        int popval = stackTwo.top();
        stackTwo.pop();
        return popval;
    }
    int peek() { // O(1)
        if(!stackTwo.empty()){
            return stackTwo.top();
        }
        return front;
    }
    bool empty() {
        return stackOne.empty() && stackTwo.empty();
    }
    ~MyQueue() {
        while(!stackOne.empty()) stackOne.pop();
        while(!stackTwo.empty()) stackTwo.pop();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */