class Solution {
private:
    vector<int> dp;
public:
    int ways(int pos, string &s) {
        if (pos >= s.size()) {
            return 1;
        }
        int &result = dp[pos];
        if (result != -1) {
            return result;
        }
        result = 0;
        int take = s[pos] - '0';
        if (take) {
            result = ways(pos + 1, s);
        }
        if (pos + 1 < s.size()) {
            take = stoi(s.substr(pos, 2));
            if (take >= 10 && take <= 26) {
                result += ways(pos + 2, s);
            }
        }
        return result;
    }
    int numDecodings(string s) {
        dp.clear();
        dp.resize(s.size(), -1);
        return ways(0, s);
    }
};