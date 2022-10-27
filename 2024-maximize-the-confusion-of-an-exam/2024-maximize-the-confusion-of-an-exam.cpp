class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int count[26] = {0};
        int length = answerKey.size(), left = 0, answer = 1, max_count = 0;
        for (int right = 0; right < length; right++) {
            max_count = max(max_count, ++count[answerKey[right] - 'A']);
            while (right - left + 1 - max_count > k) {
                count[answerKey[left] - 'A']--;
                left++;
            }
            answer = max(answer, right - left + 1);
        }
        return answer;
    }
};