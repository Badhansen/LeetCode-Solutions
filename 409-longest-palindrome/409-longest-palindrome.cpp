class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> count;
        for(auto c : s){
            count[c]++;
        }
        bool isOne = false;
        int len = 0;
        for(auto [key, value] : count){
            if(value & 1){
                len += value - 1;
                isOne = true;
            }
            else{
                len += value;
            }
        }
        if(isOne){
            return len + 1;
        }
        return len;
    }
};