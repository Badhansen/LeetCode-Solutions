class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, result = INT_MAX;
        while(left <= right){
            result = min({result, nums[left++], nums[right--]});
        }
        return result;
    }
};