class Solution {
public:
    vector<int> createLps(string& pattern){
        int len = pattern.size();
        vector<int> lps(len, 0);
        for(int i = 1, j = 0; i < len; i++){
            while(j > 0 && pattern[i] != pattern[j]){
                j = lps[j - 1];
            }
            if(pattern[i] == pattern[j]){
                lps[i] = ++j; 
            }
        }
        return lps;
    }
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        vector<int> lps = createLps(needle);
        int hLen = haystack.size(), nLen = needle.size();
        for(int i = 0, j = 0; i < hLen; i++){
            while(j > 0 && haystack[i] != needle[j]){
                j = lps[j - 1];
            }
            if(haystack[i] == needle[j]){
                if(++j == nLen){
                    return i - nLen + 1;
                }
            }
        }
        return -1;
    }
};
// Time Complexity: O(hLen + nLen)
// Space Complexity: O(nLen)