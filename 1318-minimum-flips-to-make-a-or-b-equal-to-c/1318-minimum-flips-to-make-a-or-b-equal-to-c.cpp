class Solution {
public:
    int minFlips(int a, int b, int c) {
        int result = 0;
        for (int i = 31; i >= 0; i--) {
            if (c & (1 << i)) {
                if ((a & (1 << i)) || (b & (1 << i))) {
                    continue;
                } else {
                    result++;
                }
            } else {
                if (a & (1 << i)) {
                    result++;
                } 
                if (b & (1 << i)){
                    result++;
                }
            }
        }
        return result;
    }
};