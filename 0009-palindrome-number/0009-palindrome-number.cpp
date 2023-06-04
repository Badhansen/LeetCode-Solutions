class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long res = 0, t = x;
        while(t) {
            int r = t % 10;
            res = res * 10 + r;
            t /= 10;
        }
        return x == res ? true : false;
    }
};