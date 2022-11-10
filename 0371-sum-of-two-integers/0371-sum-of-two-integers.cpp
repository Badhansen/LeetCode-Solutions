class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int mask = 0;
        for(int p = 0; p < 32; p++){
            int x, y;
            x = (a & (1 << p));
            y = (b & (1 << p));
            if(!x && !y){
                if(carry){
                    carry = 0;
                    mask |= (1 << p);
                }
            }
            else if(x && y){
                if(carry) mask |= (1 << p);
                else carry = 1;
            }
            else{
                if(!carry){
                    mask |= (1 << p);
                }
            }
        }
        return mask;
    }
};