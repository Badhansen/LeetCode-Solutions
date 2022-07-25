struct Node{
    int value;
    int minimum;
    Node* next;
};
int min(int a, int b){
    if(a < b) return a;
    return b;
}
class MinStack {
public:
    Node* root;
    MinStack() {
        root = nullptr;
    }
    
    void push(int val) {
        Node* temp = new Node;
        temp->value = val;
        temp->minimum = val;
        temp->next = root;
        if(root == nullptr){
            root = temp;
        }
        else{
            temp->minimum = min(temp->minimum, root->minimum);
            root = temp;
        }
    }
    
    void pop() {
        if(root != nullptr) root = root->next;
    }
    
    int top() {
        return root->value;
    }
    
    int getMin() {
        return root->minimum;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */