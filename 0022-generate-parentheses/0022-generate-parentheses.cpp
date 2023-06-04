// @Author: KING-SEN
// Programming Lanuage Used: C++
/*
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int total = 1 << 2 * n;
        vector<string> answer;
        
        for(int i = 0; i < total; i++){
            string result;
            int count = 0;
            for(int j = 0; j < 2 * n; j++){
                if(i & (1 << j)){
                    count++;
                    result.push_back('(');
                }
                else{
                    count--;
                    result.push_back(')');
                }
                if(count < 0) break;
            }
            if(count == 0){
                answer.push_back(result);
            }
        }
        return answer;
    }
};

// Time Complexity: O(2 ^ (2 * N) * N), for each of 2^2N sequences, we need to create and validate the swquence, which takes O(n) work.
// Space Complexity: O(2 ^ (2 * N) * N), Naively, every sequence could be valid

*/

class Solution {
private:
    int max;
public:
    void solve(int open, int close, vector<string>& ans, string ret){
        if(ret.size() == 2 * max){
            ans.push_back(ret);
            return;
        }
        if(open < max){
            ret.push_back('(');
            solve(open + 1, close, ans, ret);
            ret.pop_back();
        }
        if(close < open){
            ret.push_back(')');
            solve(open, close + 1, ans, ret);
            ret.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        max = n;
        vector<string> answer;
        solve(0, 0, answer, "");
        return answer;
    }
};