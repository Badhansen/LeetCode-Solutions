// @Author: KING-SEN

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1, max2, max3;
        int min1, min2;
        max1 = max2 = max3 = INT_MIN;
        min1 = min2 = INT_MAX;
        
        for(auto &n : nums){
            if(n <= min1){
                min2 = min1;
                min1 = n;
            }
            else if(n <= min2){
                min2 = n;
            }
            
            if(n >= max1){
                max3 = max2;
                max2 = max1;
                max1 = n;
            }
            else if(n >= max2){
                max3 = max2;
                max2 = n;
            }
            else if(n >= max3){
                max3 = n;
            }
        }
        
        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};