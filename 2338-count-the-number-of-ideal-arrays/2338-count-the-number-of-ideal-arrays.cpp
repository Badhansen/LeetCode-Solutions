// @Author: KING-SEN
// I have to solve it again, this problem can't be done with one go.
// Reference: https://youtu.be/Ar0AEWaO2Xk

const int kMaxLength = 21;
const int kTotalElement = 1e4 + 5;
const int kMod = 1e9 + 7;

class Solution {
 private:
    int lengths[kTotalElement][kMaxLength];
    int cache[kMaxLength][kTotalElement];
 public:
    Solution() {
        CalculateUniquePathLength();
    }
    void CalculateUniquePathLength() {
        memset(lengths, 0, sizeof lengths);
        for (int n = 1; n < kTotalElement; n++) {
            lengths[n][1] = 1;
            for (int multiple = n + n; multiple < kTotalElement; multiple += n) {
                for (int len = 0; len < kMaxLength - 1; len++) {
                    lengths[multiple][len + 1] = (lengths[multiple][len + 1] + lengths[n][len]) % kMod;
                }
            }
        }
    }
    
    // How many unique arrangement of length 'N', having all the values from [1, X]
    int UniqueArrangement(int position, int length) {
        if (length == 0) return (position == 0);
        if (position == 0) return 0;
        int &result = cache[position][length];
        if (result != -1) return result;
        result = (UniqueArrangement(position, length - 1) + UniqueArrangement(position - 1, length - 1)) % kMod;
        return result;
    }
    
    int idealArrays(int n, int maxValue) {
        memset(cache, -1, sizeof cache);
        int answer = 0;
        for (int num = maxValue; num >= 1; num--) {
            for (int val = 1; val < kMaxLength; val++) {
                int unique_arrangement = UniqueArrangement(val, n);
                answer = (answer + ((long long)unique_arrangement * lengths[num][val]) % kMod) % kMod;
            }
        }
        return answer;
    }
    
    ~Solution() {}
};