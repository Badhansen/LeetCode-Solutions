class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto pos = upper_bound(letters.begin(), letters.end(), target);
        if(pos == letters.end()) return *letters.begin();
        return *pos;
    }
};