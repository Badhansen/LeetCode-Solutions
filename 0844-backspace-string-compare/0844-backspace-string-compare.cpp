class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string a, b;
        for (auto &c : S) {
            if (c == '#') {
                if (!a.empty()) {
                    a.pop_back();
                }
            } else {
                a.push_back(c);
            }
        }
        for (auto &c : T) {
            if (c == '#') {
                if (!b.empty()) {
                    b.pop_back();
                }
            } else {
                b.push_back(c);
            }
        }
        return a == b;
    }
};