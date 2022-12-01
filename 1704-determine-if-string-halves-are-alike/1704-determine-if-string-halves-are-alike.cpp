class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
        }
        return false;
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        int a = 0, b = 0;
        for (int i = 0; i < n / 2; i++) {
            if (isVowel(tolower(s[i]))) {
                a++;
            }
        }
        for (int i = n / 2; i < n; i++) {
            if (isVowel(tolower(s[i]))) {
                b++;
            }
        }
        if (a != b) {
            return false;
        }
        return true;
    }
};