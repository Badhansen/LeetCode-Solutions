//solution 2: space optimized with O(1)
class Solution {
private: 
    int expand(int left, int right, string &s) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--, right++;
        }
        return right - left - 1;
    }
public:
    string longestPalindrome(string s) {
        int size = s.size(); 
        int start = 0, maxLen = 1;
        for(int i = 0; i < size; i++) {
            int len1 = expand(i, i, s);
            int len2 = expand(i, i+1, s);
            int len = max(len1, len2);
            if(len > maxLen) {
                maxLen = len; 
                start = i - (maxLen - 1) / 2;
            }
        }
                
        return s.substr(start, maxLen); 
        
    }
};
/*
Time: O(N*N)
Space: O(1)
*/

/*
// @Author: KING-SEN

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
        int maxLength = 1;
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        int start = 0;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }
        for (int p = 3; p <= n; p++) {
            for (int i = 0; i < n - p + 1; i++) {
                int j = i + p - 1;
                if (dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (maxLength < p) {
                        start = i;
                        maxLength = p;
                    }
                }
            }
        }
        return s.substr(start, maxLength);
    }
};
*/