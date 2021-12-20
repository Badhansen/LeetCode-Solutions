class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits(num + 1, 0);
        for(int i=0; i<=num; i++){
            bits[i] = __builtin_popcount(i);
        }
        return bits;
    }
};