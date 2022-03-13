class Solution {
    public int distinctSubseqII(String s) {
        int end[] = new int[26], res = 0, added = 0, mod = (int)1e9 + 7;
        for (char c : s.toCharArray()){
            added = (res + 1 - end[c - 'a']) % mod;
            res = (res + added) % mod;
            end[c - 'a'] = (end[c - 'a'] + added) % mod;
        }
        return (res + mod) % mod;
    }
}