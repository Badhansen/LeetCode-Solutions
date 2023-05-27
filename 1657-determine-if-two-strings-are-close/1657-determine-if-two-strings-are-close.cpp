class Solution {
public:
    bool closeStrings(string word1, string word2) {
        map<char, int> count1, count2;
        for (auto w : word1){
            count1[w]++;
        }
        for (auto w : word2) {
            count2[w]++;
        }
        vector<char> char1, char2;
        vector<int> freq1, freq2;
        for (auto [key, val] : count1) {
            char1.push_back(key);
            freq1.push_back(val);
        }
        for (auto [key, val] : count2) {
            char2.push_back(key);
            freq2.push_back(val);
        }
        sort(char1.begin(), char1.end());
        sort(char2.begin(), char2.end());
        if (char1 != char2) {
            return false;
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        if (freq1 != freq2) {
            return false;
        }
        return true;
    }
};