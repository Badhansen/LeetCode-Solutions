// @Author: KING-SEN
// Programming Language Used: C++

class Math{
public:
    int precedence(char op){
        if(op == '+' || op == '-')
            return 1;
        if(op == '*' || op == '/')
            return 2;
        return 0;
    }
    int applyOp(int a, int b, char op){
        if(op == '+')
            return a + b;
        else if(op == '-')
            return a - b;
        else if(op == '*')
            return a * b;
        return a / b;
    }
    int evaluation(string tokens){
        stack<int> values;
        stack<char> ops;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == ' ')
                continue;
            else if(isdigit(tokens[i])){
                int res = 0;
                while(i < tokens.size() && isdigit(tokens[i])){
                    res = res * 10 + (tokens[i] - '0');
                    i++;
                }
                values.push(res);
                i--;
            }
            else{
                while(!ops.empty() && precedence(ops.top()) >= precedence(tokens[i])){
                    int val2 = values.top();
                    values.pop();
                    int val1 = values.top();
                    values.pop();
                    
                    char op = ops.top();
                    ops.pop();
                    values.push(applyOp(val1, val2, op));
                }
                ops.push(tokens[i]);
            }
        }
        while(!ops.empty()){
            int val2 = values.top();
            values.pop();
            int val1 = values.top();
            values.pop();
            char op = ops.top();
            ops.pop();
            values.push(applyOp(val1, val2, op));
        }
        return values.top();
    }
};
class Solution {
public:
    int calculate(string s) {
        Math eval;
        return eval.evaluation(s);
    }
};

// Time Complexity: O(N), Here N = length of the string 
// Space Complexity: O(N)