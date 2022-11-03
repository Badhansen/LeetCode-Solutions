class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n) return false;
        else return !(n * 1ll & (1ll * n - 1));
    }
};