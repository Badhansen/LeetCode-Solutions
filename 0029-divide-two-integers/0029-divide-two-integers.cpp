class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int neg = (dividend < 0) ^ (divisor < 0);
        if (neg == 0) {
            return abs(dividend) / abs(divisor);
        } else {
            return -1 * (abs(dividend) / abs(divisor));
        }
    }
};
/*
class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend == -1 * (2 ** 31) and divisor == -1:
            return 1 * (2 ** 31) - 1
        neg = (dividend < 0) ^ (divisor < 0)
        if neg == 0:
            return (abs(dividend) // abs(divisor))
        else:
            return -1 * (abs(dividend) // abs(divisor))
*/