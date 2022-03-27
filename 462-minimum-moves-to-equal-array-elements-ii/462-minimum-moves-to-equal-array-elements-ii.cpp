class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1, sum = 0;
        while(start < end){
            sum += nums[end] - nums[start];
            start++;
            end--;
        }
        return sum;
    }
};