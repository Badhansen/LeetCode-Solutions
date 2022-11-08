// @Author: KING-SEN
// Programming Language Used: C++

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int length = s.size();
        unordered_map<int, int> seen;
        int start = -1;
        for(int i = 0; i < length; i++){
            if(seen.count(s[i])){
                if(seen[s[i]] > start){
                    start = seen[s[i]];
                }
            }
            result = max(result, i - start);
            seen[s[i]] = i;
        }
        
        return result;
    }
};

// Time Complexity: O(N), Where N is length of the string 
// Space Complexity: O(min(N, M)), where N is the length of the string and M is the size of the character set for HashMap
// Space Complexity: O(m), where m is the size of the charset.

