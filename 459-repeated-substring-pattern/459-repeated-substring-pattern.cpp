class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ns = s.substr(1) + s.substr(0, (int)s.size() - 1);
        return ns.find(s) != string::npos;
    }
};
