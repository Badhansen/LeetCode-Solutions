class Solution {
private:
    stack<int> stack;
public:
    int evalRPN(vector<string>& tokens) {
        for(auto &item : tokens){
            if(isdigit(item.back())){
                stack.push(stoi(item));
            }
            else{
                int num1, num2;
                num2 = stack.top();
                stack.pop();
                num1 = stack.top();
                stack.pop();
                if(item.back() == '+'){
                    stack.push(num1 + num2);
                }
                else if(item.back() == '-'){
                    stack.push(num1 - num2);
                }
                else if(item.back() == '/'){
                    stack.push(num1 / num2);
                }
                else{
                    stack.push(num1 * num2);
                }
            }
        }
        return stack.top();
    }
    ~Solution(){
        while(!stack.empty()) stack.pop();
    }
};