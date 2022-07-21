class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcd = numsDivide[0];
        for (auto n : numsDivide) {
            gcd = __gcd(gcd, n);
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(gcd % nums[i] == 0) return i; 
        }
        return -1;
    }
};