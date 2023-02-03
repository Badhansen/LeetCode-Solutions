class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>ans(min(numRows, int(s.size())));
        string result="";
        if (numRows == 1){
            return s;
        }
        bool down = false;
        int value = 0;
        for (char c : s) {
            ans[value] += c;
            if (value == 0 || value == numRows - 1) {
                down = !down;
            }
            if (down) {
                value += 1;
            } else {
                value -= 1;
            }
        }
        for (string r : ans) {
            result += r;
        }
        return result;
    }
};