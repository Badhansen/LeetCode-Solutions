class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        vector<string> res;
        string ans;
        int count = k;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != '-') {
                if (isdigit(s[i]) || isupper(s[i])) {
                    ans.push_back(s[i]);
                } else {
                    ans.push_back(toupper(s[i]));
                }
                count--;
                if (count == 0) {
                    ans.push_back('-');
                    count = k;
                }
            }
        }
        if (!ans.empty() && ans.back() == '-') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};