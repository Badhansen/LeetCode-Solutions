// @Author: KING-SEN

class Solution {
private: 
    int parseNum(string &s, int &i) {
        int value = 0; 
        while (i < s.size() && isdigit(s[i])) {
            value = value * 10 + (s[i++] - '0');
        }
        return value; 
    }
    int parseExp(string &s, int &i){
        vector<int> nums; 
        char sign = '+';
        int value = 0;
        for ( ; i < s.size() && sign != ')'; i++){
            if (s[i] == ' ') {
                continue; 
            }
            
            if (s[i] == '(') {
                value = parseExp(s, ++i);
            } else {
                value = parseNum(s, i);
            }
            
            switch(sign) {
                case '+' : 
                    nums.push_back(value); 
                    break;
                case '-' :
                    nums.push_back(-value); 
                    break;
                case '*' :
                    nums.back() *= value; 
                    break;
                case '/' :
                    nums.back() /= value; 
                    break;
            }
            sign = s[i];
        }
        
        int result = 0; 
        for(auto &num : nums)
            result += num; 
        return result; 
    }
public:
    int calculate(string s) {
        int i = 0;
        return parseExp(s, i);
    }
};