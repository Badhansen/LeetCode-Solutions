class Solution {
private:
    unordered_set<string> dict;
    unordered_set<string> formedWords;
public:
    bool dfs(string& word) {
        if (formedWords.count(word)) {
            return true;
        }
        for (int i = 1; i < word.size(); i++) {
            string s1 = word.substr(0, i);
            string s2 = word.substr(i);
            if (dict.count(s1)) {
                if (dict.count(s2) || dfs(s2)) {
                    formedWords.insert(word);
                    return true;
                }
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;
        dict = unordered_set<string>(words.begin(), words.end());
        for (auto word : words) {
            if (dfs(word)) {
                result.push_back(word);
            }
        }
        return result;
    }
};