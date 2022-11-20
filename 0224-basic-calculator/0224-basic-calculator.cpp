// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int calculate(string s) {
        int sum = 0, sign = 1;
        stack<int> stack;
        
        for(int i = 0; i < s.size(); i++){
            // Empty space
            if(s[i] == ' ')
                continue;
            // For number
            else if(isdigit(s[i])){
                int res = 0;
                while(i < s.size() && isdigit(s[i])){
                    res = res * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                sum += res * sign;
            }
            // For +
            else if(s[i] == '+'){
                sign = 1;
            }
            // For -
            else if(s[i] == '-'){
                sign = -1;
            }
            else if(s[i] == '('){
                stack.push(sum);
                stack.push(sign);
                sum = 0;
                sign = 1;
            }
            // For )
            else{
                sum = stack.top() * sum;
                stack.pop();
                sum += stack.top();
                stack.pop();
            }
        }
        
        return sum;
    }
};

// Time Complexity: O(N), Here N = length of the string 
// Space Complexity: O(N)
