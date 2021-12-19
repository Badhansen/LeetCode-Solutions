// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    string solve(string &s, int &position){
        string result;
        
        while(position < s.size() && s[position] != ']'){
            if(isalpha(s[position])){
                result.push_back(s[position]);
            }
            else{
                int number = 0;
                while(position < s.size() && s[position] != '['){
                    number = number * 10 + s[position] - '0';
                    position++;
                }
                
                position++;
                
                string tempRes = solve(s, position);
                
                while(number > 0){
                    result.append(tempRes);
                    number--;
                }
            }
            position++;
        }
        return result;
    }
    string decodeString(string s) {
        int position = 0;
        string answer = solve(s, position);
        return answer;
    }
};

// Time Complexity: O(maxK * N), Where maxK is the maximum value of k and n is the length of a given string s
// Space Complexity: O(N), This is the space used to store the internal call stack used for recursion. As we are recursively decoding each nested pattern, the maximum depth of recursive call stack would not be more than N