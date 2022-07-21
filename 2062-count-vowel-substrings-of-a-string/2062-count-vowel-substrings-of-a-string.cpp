class Solution {
public:
    int countVowelSubstrings(string word) {
        unordered_map<int, int> maps = {{'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};
        int start = 0, end = 0, vowel = 0, n = word.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (maps.count(word[i])) {
                maps[word[i]]++;
                if (maps[word[i]] == 1) vowel++;
                while (vowel == 5) {
                    maps[word[end]]--;
                    if (maps[word[end]] == 0) {
                        vowel--;
                    }
                    end++;
                }
                result += end - start;
            } else {
                maps['a'] = maps['e'] = maps['i'] = maps['o'] = maps['u'] = 0;
                vowel = 0;
                start = end = i + 1;
            }
        }
        return result;
    }
};

// Time: O(N)
// Space: O(1)