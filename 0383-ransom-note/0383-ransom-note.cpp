//@Author: KING-SEN

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(27, 0); 
        for (auto &letter : magazine) {
            count[letter - 'a']++;
        }
        for (auto &letter : ransomNote) {
            count[letter - 'a']--;
            if (count[letter - 'a'] < 0) {
                return false; 
            }
        }
        return true; 
    }
};
/*
Time: O(N)
space: O(1)
*/