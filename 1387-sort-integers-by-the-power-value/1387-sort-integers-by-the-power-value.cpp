const int kMax = 1e3;

class Solution {
private:
    int cache[kMax + 1];
public:
    Solution() {
        for(int i = 2; i <= kMax; i++) {
            cache[i] = transform(i);
        }
    }
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
            power.push_back({cache[i], i});
        }
        nth_element(power.begin(), power.begin() + k - 1, power.end());
        return power[k - 1][1];
    }
};