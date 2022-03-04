// @Author: KING-SEN

class Solution {
public:
    string longestPrefix(string s) {
        int len = s.size();
        vector<int> lps(len, 0);
        for(int i = 1, j = 0; i < len; i++){
            while(j > 0 && s[i] != s[j]){
                j = lps[j - 1];
            }
            if(s[i] == s[j]){
                lps[i] = ++j;
            }
        }
        return s.substr(0, lps[len - 1]);
    }
};

// Time: O(n), n is the length of the string 
// Space: O(n)