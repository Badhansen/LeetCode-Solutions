class Solution {
public:
    int reverse(int x) {
        bool flag = false;
        if(x == INT_MIN || x == INT_MAX) return 0;
        if(x < 0){
            flag = true;
            x = -x;
        }
        int res = 0;
        while (x) {
            int r = x % 10;
            if (res && INT_MAX / res < 10) {
                return 0;
            }
            res = res * 10 + r;
            x /= 10;
        }
        return flag ? -res : res;
    }
};