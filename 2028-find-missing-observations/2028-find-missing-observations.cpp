// @Author: KING-SEN

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int missingSum = mean * (n + m) - sum;
        if (missingSum < n || missingSum > 6 * n) {
            return {};
        }
        int remSum = missingSum % n;
        vector<int> res(n, missingSum / n);
        for (int i = 0; i < remSum; i++) {
            res[i]++;
        }
        return res;   
    }
};