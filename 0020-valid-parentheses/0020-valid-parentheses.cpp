// Programming Language Used: C++

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> stack;
        unordered_map<char, char> need; 
        need[')'] = '(';
        need['}'] = '{';
        need[']'] = '[';
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                stack.push(s[i]);
            } else{
                if (!stack.empty() && need[s[i]] == stack.top()) {
                    stack.pop();
                } else{
                    return false;
                }
            }
        }
        return stack.empty();
    }
};

// Time Complexity: O(N), Where N is the length of the string
// Space Complexity: O(N), We have to store up to the N characters in the stack