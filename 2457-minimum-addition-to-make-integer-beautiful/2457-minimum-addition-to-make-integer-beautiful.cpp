class Solution {
public:
    int digitSum(long long n) {
        int result = 0;
        while (n) {
            result += n % 10;
            n /= 10;
        }
        return result;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        if (digitSum(n) <= target) {
            return 0;
        }
        long long result = n, count = 10;
        while (digitSum(result) > target) {
            long long mod = n % count;
            result = n + count - mod;
            count *= 10;
        }
        return result - n;
    }
};