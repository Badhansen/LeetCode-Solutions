class Solution {
public:
    bool checkPalindrome(string& s, int st, int ed){
        while(st < ed){
            if(s[st] != s[ed]){
                return false;
            }
            st++, ed--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int st = 0, ed = s.size() - 1;
        while(st < ed){
            if(s[st] != s[ed]){
                return checkPalindrome(s, st, ed - 1) || checkPalindrome(s, st + 1, ed);
            }
            st++, ed--;
        }
        return true;
    }
};