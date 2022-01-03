// @Author: KING-SEN
// Programmig Language Used: C++

class Solution {
public:
    int findBestSubArray(vector<int>& nums, int start, int end){
        if(start > end)
            return INT_MIN;
        int mid = (start + end) / 2;
        int currSum = 0;
        int leftSum = 0;
        int rightSum = 0;
        for(int i = mid - 1; i >= start; i--){
            currSum += nums[i];
            leftSum = max(leftSum, currSum);
        }
        
        currSum = 0;
        
        for(int i = mid + 1; i <= end; i++){
            currSum += nums[i];
            rightSum = max(rightSum, currSum);
        }
        
        int bestSum = nums[mid] + leftSum + rightSum;
        int leftHalf = findBestSubArray(nums, start, mid - 1);
        int rightHalf = findBestSubArray(nums, mid + 1, end);
        
        return max({bestSum, leftHalf, rightHalf});
    }
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        return findBestSubArray(nums, 0, len - 1);
    }
};

// Time Complexity: O(N * log N) here N is the length of the array
// Space complexity: O(log N)