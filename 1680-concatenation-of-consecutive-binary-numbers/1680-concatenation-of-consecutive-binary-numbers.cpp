int kMod = 1e9 + 7;
int kN = 1e5;
int kBit = 32;

class Solution {
public:
    int numberOfBits(int n) {
		return log2(n) + 1;
    }
    int concatenatedBinary(int n) {
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            int bits = numberOfBits(i);
            sum = ((sum << bits) % kMod + i) % kMod;
        }
        return (int)sum;
    }
};