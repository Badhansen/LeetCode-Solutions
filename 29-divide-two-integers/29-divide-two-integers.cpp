// Not my solutiuon
class Solution {
public:
    int divide(int A, int B) {
        // for the corner case, If A is INT_MIN, and B is -1, 
        // the result will be 1 + INT_MAX, hence overflowing 
        // 32 bits, handle it first
        if (A == INT_MIN && B == -1) 
            return INT_MAX;
        
        // let's handle sign at the end, keep unsigned values for shifts
        unsigned int a = abs(A);
        unsigned int b = abs(B);
        unsigned int res = 0;
        
        // iterate over each possible factors from 1 to 2^31
        for (int x = 31; x >= 0; x--) {
            // Is it possible to reduce "a" up to a >> x
            // such that a >> x is still grater than b ?
            if ((a >> x) >= b) {
                a = a - (b << x); // adjust the dividend, substract the maximum possible multiple of b and 1 << x
                res = res + (1 << x); //update the quotient
            }
        }
        return (A > 0) == (B > 0) ? res : -res; //usual stuff, nothing fancy
    }
};