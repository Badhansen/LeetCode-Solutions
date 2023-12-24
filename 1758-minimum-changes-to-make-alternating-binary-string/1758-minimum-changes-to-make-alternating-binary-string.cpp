class Solution {
public:
    int minOperations(string s) {
        int operations = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                if (s[i] == '0') {
                    operations++;
                }
            } else {
                if (s[i] == '1') {
                    operations++;
                }
            }
        }
        return min(operations, (int)s.size() - operations);
    }
};