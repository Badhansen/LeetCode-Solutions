const int kMax = 1e5 + 5;

class Solution {
private:
    long long dp[kMax][3][4];
public:
    long long solve(int pos, int type, int sum, string& s) {
        //cout << pos << " " << type << " " << sum << endl;
        if (sum == 3) {
            return 1;
        }
        if (pos == s.size()) {
            return 0;
        }
        long long &ret = dp[pos][type][sum];
        if (ret != -1) {
            return ret;
        }
        ret = 0;
        if (s[pos] == '0') {
            if (type == 1 ||  type == 2) {
                ret += solve(pos + 1, 0, sum + 1, s);
            }
            ret += solve(pos + 1, type, sum, s);
        } else {
            if (type == 0 || type == 2) {
                ret += solve(pos + 1, 1, sum + 1, s);
            }
            ret += solve(pos + 1, type, sum, s);
        }
        return ret;
    }
    long long numberOfWays(string s) {
        memset(dp, -1, sizeof dp);
        long long answer = solve(0, 2, 0, s);
        return answer;
    }
};