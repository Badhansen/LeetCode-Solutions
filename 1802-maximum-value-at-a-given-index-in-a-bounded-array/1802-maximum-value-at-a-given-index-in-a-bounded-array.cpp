class Solution {
public:
    bool IsPossible(int index, int maxsum, int n, int guess) {
        long long sum = CalcSum(guess) + CalcSum(guess) - guess;
        int left = index + 1;
        int right = n - index;
        if (left < guess) {
            sum -= CalcSum(guess - left);
        } else {
            sum += left - guess;
        }
        if (right < guess) {
            sum -= CalcSum(guess - right);
        } else {
            sum += right - guess;
        }
        return maxsum >= sum;
    }
    long long CalcSum(long long n) {
        return n * (n + 1) / 2;
    }
    int maxValue(int n, int index, int maxSum) {
        int l = 1, r = maxSum, answer = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (IsPossible(index, maxSum, n, m)) {
                answer = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return answer;
    }
};