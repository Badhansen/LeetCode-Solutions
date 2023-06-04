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