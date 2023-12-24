class Solution {
public:
    int minSwaps(string s) {
        int start0 = 0, start1 = 0, zeros = 0; 
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                s[i] == '0' ? start1++ : start0++;
            }
            s[i] == '0' ? zeros++ : true;
        }
        int ones = (int)s.size() - zeros;
        if (abs(ones - zeros) > 1) {
            return -1;
        }
        if (zeros == ones) {
            return min(start0, start1);
        }
        return zeros > ones ? start0 : start1;
    }
};