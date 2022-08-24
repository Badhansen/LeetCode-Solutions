class Solution {
public:
    bool isPowerOfThree(int n) {
        long p = pow(3, 19);
        if(n <= 0) return false;
        if(p % n == 0) return true;
        return false;
    }
};