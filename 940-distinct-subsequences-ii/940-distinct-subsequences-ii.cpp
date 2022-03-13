class Solution {
public:
    int distinctSubseqII(string s) {
        int res = 0, added = 0, mod = 1e9 + 7, endsWith[26] = {0};
        for(auto c : s){
            added = (res + 1 - endsWith[c - 'a']) % mod;
            res = (res + added) % mod;
            endsWith[c - 'a'] = (endsWith[c - 'a'] + added) % mod;
        }
        return (res + mod) % mod;
    }
};