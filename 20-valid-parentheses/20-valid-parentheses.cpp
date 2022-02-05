// Programming Language Used: C++

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> charStack;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                charStack.push(s[i]);
            }
            else{
                if(charStack.empty()) return false;
                
                char topChar = charStack.top();
                if((topChar == '(' && s[i] == ')') || (topChar == '{' && s[i] == '}') || (topChar == '[' && s[i] == ']')){
                    charStack.pop();
                }
                else{
                    return false;
                }
            }
        }
        return charStack.empty();
    }
};

// Time Complexity: O(N), Where N is the length of the string
// Space Complexity: O(N), We have to store up to the N characters in the stack