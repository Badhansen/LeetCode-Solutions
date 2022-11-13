//@Author: KING-SEN

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> count(27, 0);
        for (auto &letter : s) {
            count[letter-'a']++;
        }
        for (auto &letter : t) {
            count[letter-'a']--;
            if (count[letter-'a'] < 0) {
                return letter; 
            }
        }
        return ' ';
    }
};
/*
Time: O(N)
Space: O(1)
*/