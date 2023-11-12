class Solution {
public:
    unordered_map<long long, bool> cache;
    vector<int> matchsticks;
    long long hashState(int i, int s1, int s2, int s3, int s4) {
        return ((long long)i | ((long long)s1 << 15) | ((long long)s2 << 30) | ((long long)s3 << 45) | ((long long)s4 << 60));
    }
    bool solve(int i, int s1, int s2, int s3, int s4) {
        long long state = hashState(i, s1, s2, s3, s4);
        if (cache.count(state)) {
            return cache[state];
        }
        if (i >= matchsticks.size()) {
            return (s1 == s2 && s2 == s3 && s3 == s4);
        }
        cache[state] = (s1 >= matchsticks[i] && solve(i + 1, s1 - matchsticks[i], s2, s3, s4))
                    || (s2 >= matchsticks[i] && solve(i + 1, s1, s2 - matchsticks[i], s3, s4))
                    || (s3 >= matchsticks[i] && solve(i + 1, s1, s2, s3 - matchsticks[i], s4))
                    || (s4 >= matchsticks[i] && solve(i + 1, s1, s2, s3, s4 - matchsticks[i]));
        return cache[state];
    }
    bool makesquare(vector<int>& m) {
        int sum = accumulate(m.begin(), m.end(), 0);
        this->matchsticks = m;
        if (sum % 4) {
            return false;
        }
        sort(matchsticks.rbegin(), matchsticks.rend());
        return solve(0, sum / 4, sum / 4, sum / 4, sum / 4);
    }
};