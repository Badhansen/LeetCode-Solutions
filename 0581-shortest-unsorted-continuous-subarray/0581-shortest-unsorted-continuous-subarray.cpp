// @Author: KING-SEN

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> increasing, decreasing; 
        // Increasing stack previous lesser and next lesser elelments
        // Decresing stack previous greater and next greater elements
        int n = nums.size();
        int left = n, right = 0, end = n - 1;
        for (int i = 0; i < n; i++) {
            while (!increasing.empty() && nums[increasing.top()] > nums[i]) {
                left = min(left, increasing.top());
                increasing.pop();
            }
            while (!decreasing.empty() && nums[decreasing.top()] < nums[end - i]) {
                right = max(right, decreasing.top());
                decreasing.pop();
            }
            increasing.push(i);
            decreasing.push(end - i);
        }
        int total = right - left + 1;
        return total < 0 ? 0 : total; 
    }
};