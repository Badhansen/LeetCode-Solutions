class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> count(256, 0);
        int unique_character = 0; 
        int answer = INT_MAX;
        int start_index = 0;
        for (auto c : t) {
            if (count[c] == 0) {
                unique_character++;
            }
            count[c]++;
        }
        int start = 0, end = 0, length = s.size();
        while (end < length) {
            count[s[end]]--;
            if (count[s[end]] == 0) {
                unique_character--;
            }
            end++;
            if (unique_character == 0) {
                while (unique_character == 0) {
                    if (answer > end - start) {
                        answer = end - start;
                        start_index = start;
                    }
                    count[s[start]]++;
                    if(count[s[start]] > 0) {
                        unique_character++;
                    }
                    start++;
                }
            }
        }
        return answer == INT_MAX ? "" : s.substr(start_index, answer);
    }
};