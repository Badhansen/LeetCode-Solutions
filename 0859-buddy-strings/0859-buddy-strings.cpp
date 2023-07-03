class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size() || s.size() == 1) {
            return false;
        }
        if (s == goal) {
            unordered_set<char> distinctChars(s.begin(), s.end());
            return distinctChars.size() < s.length();
        }
        vector<int> id;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) {
                id.push_back(i);
            }
        }
        if (id.size() != 2) {
            return false;
        }
        swap(s[id[0]], s[id[1]]);
        return s == goal;
    }
};