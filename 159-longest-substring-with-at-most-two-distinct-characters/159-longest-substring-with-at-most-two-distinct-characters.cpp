// @Author: KING-SEN
// 1 last try

class Solution {
public:
    int AtMostKDistinct(string s, int k) {
        unordered_map<int, int> freq;
        int start = 0, end = 0, answer = 0, count = 0;
        for (int end = 0; end < s.size(); end++) {
            freq[s[end]]++;
            while (freq.size() > k) {
                freq[s[start]]--;
                if (freq[s[start]] == 0) {
                    freq.erase(s[start]);
                }
                start++;
            }
            answer = max(answer,  end - start + 1);
        }
        return answer;
    }
    int lengthOfLongestSubstringTwoDistinct(string s) {
        return AtMostKDistinct(s, 2);
    }
};