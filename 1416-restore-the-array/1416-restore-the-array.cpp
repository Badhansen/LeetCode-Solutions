const int Mod = 1e9 + 7;

class Solution {
private: 
    vector<int> dp;
public:
    int ways(int pos, string& s, int k) {
        if (pos == s.size()) {
            return 1;
        }
        int &ret = dp[pos];
        if (ret != -1) {
            return ret;
        }
        if (s[pos] == '0') {
            return 0;
        }
        ret = 0;
        for (int i = pos; i < s.size(); i++) {
            string currNumber = s.substr(pos, i - pos + 1);
            if (stoll(currNumber) > k) {
                break;
            }
            ret = (ret + ways(i + 1, s, k) % Mod) % Mod;
        }
        return ret;
    }
    int numberOfArrays(string s, int k) {
        int n = s.size();
        dp.resize(n, -1);
        return ways(0, s, k);
    }
};