class Solution {
public:
    long long numberOfWays(string s) {
        int ones = 0, zeros = 0;
        for (auto c : s) {
            if (c == '0') {
                zeros++;
            } else {
                ones++;
            }
        }
        int prevOnes = 0, prevZeros = 0;
        long long answer = 0;
        for (auto c : s) {
            if (c == '0') {
                zeros--;
            } else {
                ones--;
            }
            if (c == '0') {
                answer += (ones * prevOnes);
                prevZeros++;
            } else {
                answer += (zeros * prevZeros);
                prevOnes++;
            }
        }
        return answer;
    }
};