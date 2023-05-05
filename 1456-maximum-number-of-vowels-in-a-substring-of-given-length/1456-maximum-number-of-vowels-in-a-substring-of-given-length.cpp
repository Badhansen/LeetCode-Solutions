class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0, ans = 0;
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        for (int right = 0; right < s.size(); right++) {
            if (right >= k) {
                count += vowels.count(s[right]) - vowels.count(s[right - k]);
            } else {
                count += vowels.count(s[right]);
            }
            ans = max(ans, count);
        }
        return ans;
    }
};