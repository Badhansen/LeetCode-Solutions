class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(256, 0);
        int s_len = s.size(), t_len = t.size();
        for(int i = 0; i < max(s_len, t_len); i++){
            if (i < s_len) {
                count[s[i]]++;
            }
            if (i < t_len) {
                count[t[i]]--;
            }
        }
        for(int i = 0; i < 256; i++){
            if (count[i] != 0) {
                return false;
            }
        }
        return true;
    }
};