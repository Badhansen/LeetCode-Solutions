class Solution {
public:
    int countGoodSubstrings(string s) {
        int result = 0, start = 0, mid, end = 2;
        if (s.size() <= end) return 0;
        while (end < s.size()) {
            mid = start + 1;
            if (s[start] != s[mid] && s[mid] != s[end] && s[end] != s[start]) {
                result++;
            }
            start++;
            end++;
        }
        return result;
    }
};
/*
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
*/