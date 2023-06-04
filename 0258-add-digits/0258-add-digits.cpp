class Solution {
public:
    int addDigits(int num) {
        while(num > 9){
            int res = 0;
            while(num){
                res += num % 10;
                num /= 10;
            }
            num = res;
        }
        return num;
    }
};