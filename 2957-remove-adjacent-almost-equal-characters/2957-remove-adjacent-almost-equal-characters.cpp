class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int minOperations = 0;
        for (int i = 1; i < word.size(); i++) {
            if (abs(word[i] - word[i - 1]) <= 1) {
                minOperations++, i++;
            }
        }
        return minOperations;
    }
};