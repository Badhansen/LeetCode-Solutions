class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int result = 0;
        for (int i = 0, j = 0; i < word.size(); i++) {
            if (word[i] == 'a') {
                int count = 0;
                for (j = i + 1; j < word.size() && word[j - 1] <= word[j]; j++) {
                    count += word[j - 1] < word[j];
                }
                if (count == 4) {
                    result = max(result, j - i);
                }
                i = j - 1;
            }
        }
        return result;
    }
};