class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> counts;
        for (auto &word : words) {
            for (auto &c : word) {
                counts[c]++;
            }
        }
        int n = words.size();
        for (auto [key, val] : counts) {
            if (val % n != 0) {
                return false;
            }
        }
        return true;
    }
};

// Time: O(N * Length of word)
// Space: O(1)