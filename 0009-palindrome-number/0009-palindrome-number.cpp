class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string rev = to_string(x);
        reverse(rev.begin(), rev.end());
        return rev == to_string(x);
        // long res = 0, t = x;
        // while(t) {
        //     int r = t % 10;
        //     res = res * 10 + r;
        //     t /= 10;
        // }
        // return x == res ? true : false;
    }
};