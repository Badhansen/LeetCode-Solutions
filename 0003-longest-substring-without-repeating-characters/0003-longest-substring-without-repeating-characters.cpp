// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i < s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};

// Time Complexity: O(N), Where N is length of the string 
// Space Complexity: O(min(N, M)), where N is the length of the string and M is the size of the character set for HashMap
// Space Complexity: O(m), where m is the size of the charset.

