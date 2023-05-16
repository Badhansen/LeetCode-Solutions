// @Author: KING-SEN

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack;
        int left = 0;
        for (int i = 0; i < pushed.size(); i++) {
            stack.push(pushed[i]);
            while (!stack.empty() && left < popped.size() && stack.top() == popped[left]) {
                left++;
                stack.pop();
            }
        }
        while (!stack.empty() && left < popped.size() && stack.top() == popped[left]) {
            left++;
            stack.pop();
        }
        return stack.empty() && left == popped.size();
    }
};