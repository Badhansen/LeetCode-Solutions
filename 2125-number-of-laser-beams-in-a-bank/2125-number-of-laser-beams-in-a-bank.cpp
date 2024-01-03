class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int answer = 0, prev = 0;
        for (auto &b : bank) {
            int curr = 0;
            for (auto &c : b) {
                if (c == '1') {
                    curr++;
                }
            }
            if (curr) {
                answer += (prev * curr);
                prev = curr;
            }
        }
        return answer;
    }
};