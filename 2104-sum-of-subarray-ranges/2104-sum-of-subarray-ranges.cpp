// @Author: KING-SEN

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long answer = 0;
        // Decreasing stack => finds the previous Greater and next greater elements
        stack<int> stack;
        for (int right = 0; right <= n; right++) {
            while (!stack.empty() && (right == n || nums[stack.top()] <= nums[right])) {
                int mid = stack.top();
                stack.pop();
                int left = stack.empty() ? -1 : stack.top();
                answer += 1ll * nums[mid] * (mid - left) * (right - mid);
            }
            stack.push(right);
        }
        
        // Increasing stack => finds the previous Lesser and next Lesser elements
        stack.pop();
        for (int right = 0; right <= n; right++) {
            while (!stack.empty() && (right == n || nums[stack.top()] >= nums[right])) {
                int mid = stack.top();
                stack.pop();
                int left = stack.empty() ? -1 : stack.top();
                answer -= 1ll* nums[mid] * (mid - left) * (right - mid);
            }
            stack.push(right);
        }
        return answer;
    }
};
