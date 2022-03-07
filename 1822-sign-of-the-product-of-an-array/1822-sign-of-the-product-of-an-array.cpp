// @Author: KING-SEN

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0, posi = 0;
        for(auto n : nums){
            if(n < 0){
                neg++;
            }
            else if(n > 0){
                posi++;
            }
            else{
                return 0;
            }
        }
        if(neg % 2 == 0){
            return 1;
        }
        return -1;
    }
};