class Solution {
public:
    unordered_map<string, bool> cache;
    string hashState(int index, vector<int> sums) {
        sort(sums.begin(), sums.end());
        string state = to_string(index);
        for (auto &s : sums) {
            state.append("|" + to_string(s));
        }
        return state;
    }
    bool solve(int index, vector<int>& sums, int target, vector<int>& sticks) {
        string state = hashState(index, sums);
        if (index >= sticks.size()) {
            return cache[state] = (sums[0] == sums[1] && sums[1] == sums[2] && sums[2] == sums[3]);
        }
        if (cache.count(state)) {
            return cache[state];
        }
        cache[state] = false;
        for (int i = 0; i < 4; i++) {
            if (sums[i] + sticks[index] <= target) {
                sums[i] += sticks[index];
                cache[state] = cache[state] || solve(index + 1, sums, target, sticks);
                sums[i] -= sticks[index];
            }
        }
        return cache[state];
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4) {
            return false;
        }
        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<int> sums(4, 0);
        return solve(0, sums, sum / 4, matchsticks);
    }
};