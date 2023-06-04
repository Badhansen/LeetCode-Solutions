class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0, answer = 1, max_count = 0;
        for (int right = 0; right < s.size(); right++) {
            max_count = max(max_count, ++count[s[right] - 'A']);
            while (right - left + 1 - max_count > k) {
                --count[s[left] - 'A'];
                left++;
            }
            answer = max(answer, right - left + 1);
        }
        return answer;
    }
};

/*
class Solution {
private:
    vector<vector<int>> _char_count;
public:
    bool isValid(string& s, int length, int k) {
        int max_count = 0;
        for (int i = length; i <= s.size(); i++) {
            max_count = 0;
            for (int j = 0; j < 26; j++) {
                int count = _char_count[i][j] - _char_count[i - length][j];
                max_count = max(max_count, count);
            }
            if (length - max_count <= k) {
                return true;
            }
        }
        return false;
    }
    int characterReplacement(string s, int k) {
        int length = s.size();
        _char_count.resize(length + 1, vector<int>(26, 0));
        for (int i = 1; i <= length; i++) {
            _char_count[i][s[i - 1] - 'A']++;
            for (int j = 0; j < 26; j++) {
                _char_count[i][j] += _char_count[i - 1][j];
            }
        }
        int low = 1, high = length, answer = 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isValid(s, mid, k)) {
                answer = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return answer;
    }
};
*/