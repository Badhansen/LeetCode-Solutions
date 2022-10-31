class Solution {
public:
    int ReverseDigit(int num) {
        int reverse_num = 0;
        while (num) {
            int rem = num % 10;
            num /= 10;
            reverse_num = reverse_num * 10 + rem;
        }
        return reverse_num;
    }
    bool isSameAfterReversals(int num) {
        if (ReverseDigit(ReverseDigit(num)) == num) {
            return true;
        }
        return false;
    }
};