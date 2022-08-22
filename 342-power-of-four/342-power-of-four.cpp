class Solution {
public:
    bool isPowerOfFour(int num) {
        int pos;
        if(num < 0) return false;
        for(int i = 31; i >= 0; i--){
            if((1 << i) & num){
                pos = i;
                break;
            }
        }
        return __builtin_popcount(num) == 1 && !(pos & 1);
    }
};