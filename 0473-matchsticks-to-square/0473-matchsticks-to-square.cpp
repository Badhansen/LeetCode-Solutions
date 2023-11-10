class Solution {
public:
    bool solve(int index, vector<int>& sums, int target, vector<int>& sticks) {
        if (index >= sticks.size()) {
            return sums[0] == sums[1] && sums[1] == sums[2] && sums[2] == sums[3];
        }
        for (int i = 0; i < 4; i++) {
            if (sums[i] + sticks[index] > target) {
                continue;
            }
            sums[i] += sticks[index];
            if (solve(index + 1, sums, target, sticks)) {
                return true;
            }
            sums[i] -= sticks[index];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4) {
            return false;
        }
        //sort(matchsticks.begin(), matchsticks.end());
        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<int> sums(4, 0);
        return solve(0, sums, sum / 4, matchsticks);
    }
};