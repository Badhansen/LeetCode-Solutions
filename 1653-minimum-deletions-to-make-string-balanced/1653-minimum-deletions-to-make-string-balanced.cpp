//@Author: KING-SEN

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int count_b = 0;
        int count_a = 0;
        int res_b_a = 0;
        for (int i=0; i<n; ++i){
            if (s[i] == 'a'){
                ++count_a;
            } else {
                ++count_b;
            }
            res_b_a = min(
                res_b_a,
                count_b - count_a
            );
        }
        return res_b_a + count_a;
    }
};

// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
