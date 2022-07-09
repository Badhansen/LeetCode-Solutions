// @Author: KING-SEN
// 1 last try

class MyQueue {
private:
    stack<int> stack1, stack2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        // 1 -> pop
        // 2
        // 3
        stack1.push(x);
    }
    
    int pop() {
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        int popval = stack2.top();
        stack2.pop();
        // 3
        // 2
        // 1
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return popval;
    }
    
    int peek() {
        // 3
        // 2
        // 1
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        int peekval = stack2.top();
        // 3
        // 2
        // 1
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return peekval;
    }
    
    bool empty() {
        return stack1.empty();
    }
    ~MyQueue() {
        while(!stack1.empty()) stack1.pop();
        while(!stack2.empty()) stack2.pop();
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