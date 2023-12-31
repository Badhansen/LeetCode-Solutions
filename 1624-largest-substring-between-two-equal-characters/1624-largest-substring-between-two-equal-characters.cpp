class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> seen(26, -1);
        int maxLen = -1;
        for (int i = 0; i < s.size(); i++) {
            if (seen[s[i] - 'a'] != -1) {
                maxLen = max(maxLen, i - seen[s[i] - 'a'] - 1);
            }
            else {
                seen[s[i] - 'a'] = i;
            }
        }
        return maxLen;
    }
};