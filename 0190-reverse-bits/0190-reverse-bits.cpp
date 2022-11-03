class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t mask = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                mask |= (1 << (31 - i));
            }
        }
        return mask;
    }
};