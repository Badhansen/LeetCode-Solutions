class Solution {
public:
    int transform(int n) {
        if (n == 1) {
            return 0;
        }
        int result = 0;
        if (n & 1) {
            result = 1 + transform(n * 3 + 1);
        } else {
            result = 1 + transform(n / 2);
        }
        return result;
    }
    int getKth(int lo, int hi, int k) {
        vector<array<int, 2>> power;
        for (int i = lo; i <= hi; i++) {
            int score = transform(i);
            power.push_back({score, i});
        }
        sort(power.begin(), power.end());
        return power[k - 1][1];
    }
};