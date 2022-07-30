class Solution {
public:
    int longestSubstring(string s, int k) {
        int answer = 0;
        for (int curr_unique = 1; curr_unique <= 26; curr_unique++) {
            vector<int> freq(26, 0);
            int left = 0, right = 0, n = s.size(), unique = 0, count_k = 0;
            while (right < n) {
                if (unique <= curr_unique) {
                    freq[s[right] - 'a']++;
                    if (freq[s[right] - 'a'] == 1){
                        unique++;
                    }
                    if (freq[s[right] - 'a'] == k) {
                        count_k++;
                    }
                    right++;
                } else {
                    if (freq[s[left] - 'a'] == k) {
                        count_k--;
                    }
                    freq[s[left] - 'a']--;
                    if (freq[s[left] - 'a'] == 0) {
                        unique--;
                    }
                    left++;
                }
                if (unique == count_k && unique == curr_unique) answer = max(answer, right - left);
            }
        }
        return answer;
    }
};