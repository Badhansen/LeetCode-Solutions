// @Author: KING-SEN

class Solution {
public:
    void reverseWords(vector<char>& s) {
        int left = 0, right = 0, n = s.size();
        reverse(s.begin(), s.end());
        while (left < n) {
            while (right < n && s[right] != ' ') {
                right++;
            }
            reverse(s.begin() + left, s.begin() + right);
            right++;
            left = right;
        }
    }
};