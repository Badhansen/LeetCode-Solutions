// @Author: KING-SEN
// 1 last try

class MyQueue {
private:
    stack<int> stackOne, stackTwo;
public:
    MyQueue() {
        
    }
    void push(int x) {
        stackOne.push(x);
    }
    int pop() {
        while(!stackOne.empty()){
            int n = stackOne.top();
            stackOne.pop();
            stackTwo.push(n);
        }
        int popval = stackTwo.top();
        stackTwo.pop();
        while(!stackTwo.empty()){
            int n = stackTwo.top();
            stackTwo.pop();
            stackOne.push(n);
        }
        return popval;
    }
    int peek() {
        while(!stackOne.empty()){
            stackTwo.push(stackOne.top());
            stackOne.pop();
        }
        int peekval = stackTwo.top();
        while(!stackTwo.empty()){
            stackOne.push(stackTwo.top());
            stackTwo.pop();
        }
        return peekval;
    }
    bool empty() {
        return stackOne.empty();
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