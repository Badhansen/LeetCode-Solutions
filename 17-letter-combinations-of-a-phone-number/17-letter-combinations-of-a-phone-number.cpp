// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
private:
    unordered_map<int, string> letters;
    vector<string> combinations;
public:
    Solution(){
        letters[2] = "abc";
        letters[3] = "def";
        letters[4] = "ghi";
        
        letters[5] = "jkl";
        letters[6] = "mno";
        letters[7] = "pqrs";
        
        letters[8] = "tuv";
        letters[9] = "wxyz";
    }
    
    void backtrack(int pos, string& digits, string path){
        if(pos == digits.size()){
            combinations.push_back(path);
            return;
        }
        
        string possibleLetters = letters[digits[pos] - '0'];
        
        for(auto &letter : possibleLetters){
            path.push_back(letter);
            
            backtrack(pos + 1, digits, path);
            
            path.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        
        backtrack(0, digits, "");
        
        return combinations;
    }
};

// Time Complexity: O(4^N * N), where N is the length of digits. Note 4 in the expression referring to the maximum value length in the map
// Space Complexity: O(N), where N is the length of digits.
// Not counting space for output, the extra space we use relative to input size is the space occupied by the recursion call stack.