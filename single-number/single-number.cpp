class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorNum = 0;
        for(int i=0; i<nums.size(); i++){
            xorNum ^= nums[i];
        }
        return xorNum;
    }
};