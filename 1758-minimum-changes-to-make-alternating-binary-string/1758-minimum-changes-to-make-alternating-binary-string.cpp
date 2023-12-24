class Solution {
public:
    int minOperations(string s) {
        int start0 = 0, start1 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                s[i] == '0' ? start1++ : start0++;
            } else {
                s[i] == '0' ? start0++ : start1++;
            }
        }
        return min(start0, start1);
    }
};