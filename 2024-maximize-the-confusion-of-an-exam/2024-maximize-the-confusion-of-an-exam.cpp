class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int count[2] = {0};
        int length = answerKey.size(), left = 0, answer = 1, max_count = 0;
        for (int right = 0; right < length; right++) {
            if (answerKey[right] == 'T') {
                count[0]++;
            } else {
                count[1]++;
            }
            max_count = max({max_count, count[0], count[1]});
            while (right - left + 1 - max_count > k) {
                if (answerKey[left] == 'T') {
                    count[0]--;
                } else {
                    count[1]--;
                }
                left++;
            }
            answer = max(answer, right - left + 1);
        }
        return answer;
    }
};