class Solution {
public:
    int findComplement(int num) {
        int i = 30;
        for(i; i > 0; i--){
            if(num & (1 << i)){
                break;
            }
        }
        int mask = 0;
        for(i; i >= 0; i--){
            bool flag = num & (1 << i);
            if(flag == false){
                mask |= (1 << i);
            }
        }
        return mask;
    }
};