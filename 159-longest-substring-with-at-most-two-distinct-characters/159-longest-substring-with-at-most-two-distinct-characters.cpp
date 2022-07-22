// @Author: KING-SEN
// 1 last try

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int k = 2;
        vector<int> freq(255, 0);
        int start = 0, end = 0, answer = 0, count = 0;
        for (int end = 0; end < s.size(); end++) {
            freq[s[end]]++;
            if (freq[s[end]] == 1) count++;
            
            if (count <= k){
                answer = max(answer, end - start + 1);
            } else {
                while (start <= end && count > k) {
                    freq[s[start]]--;
                    if (freq[s[start]] == 0) count--;
                    start++;
                }
            }
        }
        return answer;
    }
};