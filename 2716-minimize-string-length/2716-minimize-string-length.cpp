class Solution {
public:
    int minimizedStringLength(string s) {
        set<char> count;
        for (auto c : s) {
            count.insert(c);
        }
        return count.size();
    }
};