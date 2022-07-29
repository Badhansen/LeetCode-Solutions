class Solution {
public:
    int countGoodSubstrings(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            set<char> count;
            for (int j = i, k = 3; j < s.size() && k; j++, k--) {
                count.insert(s[j]);
            }
            if (count.size() == 3) result++;
        }
        return result;
    }
};